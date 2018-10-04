#include "lem_in.h"

int new_path_list(t_lemin *l, t_pathlist *paths)
{
	t_path			*tmp;
	t_pathlist	*new_paths;

	ft_putstr("In new_path_list\n");
	if (!paths->start)
		return (0);
	tmp = paths->start;
	if (!(new_paths = init_pathlist()))
	{
		ft_putstr("init_pathlist failed\n");
		return (0);
	}
	while (tmp)
	{
		ft_putstr("----------NEW PATH ANALYSIS---------\n");
		if (!tmp->ended)
		{
			new_paths = add_new_paths(l, tmp);
			print_path(tmp);
			if (tmp->ended)
			{
				ft_putstr("NEED TO DELETE\n");
				delete_used_paths(paths, tmp);
				ft_putstr("delete_used_paths successful\n");
				tmp = tmp->next;
			}
			else
			{
				tmp = merge_paths(paths, new_paths, tmp);
				ft_putstr("Merge Successful\n");
			}
		}
		else
			tmp = tmp->next;
	}
	return (1);
}
