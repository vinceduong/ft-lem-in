#include "lem_in.h"

int	count_new_childs(t_lemin *l, t_nodelist *nl, t_path *p)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < l->m.nbcases)
	{
		if (i && l->m.graph[p->curr][i] != 0 && check_nodelist(nl, i))
			count++;
		i++;
	}
	p->childs = count;
	return (1);
}

int compare_childs(t_path *p1, t_path *p2)
{
	return (p1->childs > p2->childs);
}

int compare_length(t_path *p1, t_path *p2)
{
	return (p1->nodes->length > p2->nodes->length);
}

void sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2))
{
	t_path 			*tmp;
	t_path			*tmpsort;

	tmp = paths->start;
	while (tmp->next)
	{
		if (comp(tmp, tmp->next))
		{
			tmpsort = tmp->next->next;
			tmp->next->next = tmp->next;
			tmp->next = tmpsort;
			tmpsort = tmp->next->previous;
			tmp->next->previous = tmp->previous;
			tmp->previous = tmpsort;
			tmp = paths->start;
		}
		else
			tmp = tmp->next;
	}
}

t_pathlist	*add_new_paths(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_path *p)
{
	int					i;
	int					new_childs;
	t_pathlist	*new_paths;
	t_node			*new_node;

	i = 0;
	new_childs = 0;
	if (!(new_paths = init_pathlist()))
		return (NULL);
	while (i < l->m.nbcases && ! p->ended)
	{
		if (i && l->m.graph[p->curr][i] && !check_nodelist(bl, i))
		{
			if (!(new_node = new_node(i)))
				return (NULL);
			if (i == l->m.nbcases - 1)
			{
				p->ended = 1;
				add_node(p->nodes, new_node);
			}
			else
			{
				add_path(new_paths, new_path(p, i));
				add_node(nl, new_node);
				new_childs++;
			}
		}
		i++;
	}
	return (p->ended ? NULL : (new_childs > 0 ? new_paths : NULL));
}

int new_path_list(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths)
{
	t_path			*tmp;
	t_pathlist	*new_paths;

	tmp = paths->start;
	if (!(new_paths = init_pathlist()))
		return (0);
	while (tmp)
	{
		if (!tmp->ended)
		{
			new_paths = add_new_paths(l, nl, bl, tmp);
			if (new_paths->start == tmp && tmp->ended)
			{
				update_bl(bl, tmp);
				tmp = tmp->next;
			}
			else if (new_paths)
				tmp = merge_paths(paths, new_paths, tmp);
			else
				tmp = delete_path(paths, tmp);
		}
		else
			tmp = tmp->next;
	}
	return (1);
}

int	update_paths(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths)
{
	t_path *tmp;
	int		 ended;
	t_node *check;
	ended = 0;
	tmp = paths->start;
	while (tmp)
	{
		count_new_childs(l, nl, tmp);
		tmp = tmp->next;
	}
	sort_paths(paths, &compare_childs);
	new_path_list(l, nl, bl, paths);
	tmp = paths->start;
	while (tmp)
	{
		check = tmp->nodes->start;
		while (check)
		{
			if (check_nodelist(bl, check->nb))
			{
				tmp = delete_path(paths, tmp);
				continue ;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int findpathlist(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths)
{
	t_path *path;

	if (!paths->start)
	{
		path = new_path(NULL, 0);
		add_path(paths, path);
	}
	else
	{
		if (!update_paths(l, nl, bl, paths))
			return (0);
	}
	return (findpathlist(l, nl, bl, paths));
}

t_path *list_to_sorted_array(t_pathlist *paths)
{
	t_path	*tmp;
	t_path	*array;
	int			size;
	int			i;

	size = 0;
	tmp = paths->start;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (!(array = (t_path *)malloc(sizeof(t_path) * size)))
		return (NULL);
	sort_paths(paths, &compare_length);
	tmp = paths->start;
	i = 0;
	while (tmp)
	{
		array[i] = *tmp;
		i++;
		tmp = tmp->next;
	}
	return (array);
}

int 	paths(t_lemin *l)
{
		t_nodelist	*nl;
		t_nodelist	*bl;
		t_pathlist	*paths;
		t_path			*array;

		if (!(paths = init_pathlist()))
			return (0 );
		if (!(nl = init_nodelist()))
			return (0);
		if (!(bl = init_nodelist()))
			return (0);
		if (!findpathlist(l, nl, bl, paths))
			return (0);
		if (!(array = list_to_sorted_array(paths)))
			return (0);
		l->p = array;
		return (1);
}
