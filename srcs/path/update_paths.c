#include "lem_in.h"

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
