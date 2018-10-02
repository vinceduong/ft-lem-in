#include "lem_in.h"

#define STARTS l->m.starts_tunnels
#define END l->m.end_tunnels
#define NBCASES l->map.nbcases

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

void sort_paths(t_pathlist *paths)
{
	t_path 			*tmp;
	t_path			*tmpsort;

	tmp = paths->start;
	while (tmp->next->next)
	{
		if (tmp->childs > tmp->next->childs)
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

	i = 0;
	new_childs = 0;
	new_paths = (t_pathlist*)malloc(sizeof(t_pathlist));
	while (i < l->m.nbcases && ! p->ended)
	{
		if (i && l->m.graph[p->curr][i] && !check_nodelist(bl, i))
		{
			if (i == l->m.nbcases - 1)
				p->ended = 1;
			else
			{
				add_path(new_paths, new_path(p, i));
				add_node(nl, new_node(i));
				new_childs++;
			}
		}
		i++;
	}
	return (p->ended ? NULL : (new_childs > 0 ? new_paths : NULL));
}

void new_path_list(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths)
{
	t_path *tmp;
	t_pathlist *new_paths;
	tmp = paths->start;

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
	sort_paths(paths);
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

void findpathlist(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths)
{
	t_path *path;

	if (!paths->start)
	{
		path = new_path(NULL, 0);
		add_path(paths, path);
	}
	else
	{
		if (update_paths(l, nl, bl, paths))
			return ;
	}
	findpathlist(l, nl, bl, paths);
}

int	path(t_lemin *l)
{
		t_nodelist	*nl;
		t_nodelist	*bl;
		t_pathlist	*paths;

		paths = (t_pathlist*)malloc(sizeof(t_pathlist));
		nl = (t_nodelist*)malloc(sizeof(t_nodelist));
		bl = (t_nodelist*)malloc(sizeof(t_nodelist));
		findpathlist(l, nl, bl, paths);
		return (1);
}
