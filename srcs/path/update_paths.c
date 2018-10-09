#include "lem_in.h"

int			compare_childs(t_path *p1, t_path *p2)
{
	if (!p1->ended && !p2->ended)
		return (p1->childs > p2->childs);
	return (0);
}

t_pathlist	*update_paths(t_lemin *l, t_pathlist *paths)
{
	t_path		*tmp;
	int			ended;
	t_pathlist	*newlist;

	ended = 1;
	tmp = paths->start;
	while (tmp)
	{
		if (!tmp->ended && !count_new_childs(l, tmp))
			tmp = delete_path(paths, tmp);
		else if (!tmp->ended)
		{
			ended = 0;
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	if (!paths->start)
		return (NULL);
	if (ended)
		return (paths);
	sort_paths(paths, compare_childs);
	if (!(newlist = new_path_list(l, paths)))
		return (0);
	tmp = newlist->start;
	while (tmp)
	{
		if (tmp->ended)
			delete_used_paths(newlist, tmp, l->m.nbcases - 1);
		tmp = tmp->next;
	}
	return (newlist);
}
