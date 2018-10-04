#include "lem_in.h"

int compare_childs(t_path *p1, t_path *p2)
{
	return (p1->childs > p2->childs);
}

int	update_paths(t_lemin *l, t_pathlist *paths)
{
	ft_putstr("In update_path\n");
	t_path *tmp;
	int		 ended;

	ended = 0;
	tmp = paths->start;
	while (tmp)
	{
		if (!count_new_childs(l, tmp))
		{
			ft_putstr("No childs\n");
			tmp = delete_path(paths, tmp);
		}
		ft_putstr("count_new_childs worked\n");
		tmp = tmp->next;
	}
	sort_paths(paths, compare_childs);
	ft_putstr("sort_paths worked\n");
	new_path_list(l, paths);
	tmp = paths->start;
	while (tmp)
	{
		if (!tmp->ended)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
