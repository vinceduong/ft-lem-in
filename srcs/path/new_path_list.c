#include "lem_in.h"

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
