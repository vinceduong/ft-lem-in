#include "lem_in.h"

int			compare_childs(t_path *p1, t_path *p2)
{
	if (!p1->ended && !p2->ended)
		return (p1->childs > p2->childs);
	return (0);
}

void		fill_childs(t_lemin *l, t_pathlist *paths)
{
	t_path		*tmp;

	tmp = paths->start;
	while (tmp)
	{
		if (!tmp->ended && !count_new_childs(l, tmp))
		{
			if (!(tmp = delete_path(paths, tmp)))
				return ;
		}	
		else
			tmp = tmp->next;
	}
}

t_pathlist	*update_paths(t_lemin *l, t_pathlist *paths)
{
	t_pathlist	*newlist;
	t_path		*tmp;

	fill_childs(l, paths);
	if (!paths->start)
		return (NULL);
	sort_paths(paths, compare_childs);
	if (!(newlist = new_path_list(l, paths)))
		return (NULL);
	tmp = newlist->start;
	while (tmp)
	{
		if (tmp->ended)
			delete_used_paths(newlist, tmp, l->m.nbcases - 1);
		tmp = tmp->next;
	}
	return (newlist);
}
