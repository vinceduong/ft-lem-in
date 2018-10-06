#include "lem_in.h"

t_pathlist *new_path_list(t_lemin *l, t_pathlist *paths)
{
	t_path			*tmp;
	t_pathlist	*new_paths;

	ft_putstr("In new_path_list\n");
	if (!paths->start)
		return (NULL);
	tmp = paths->start;
	if (!(new_paths = init_pathlist()))
	{
		ft_putstr("init_pathlist failed\n");
		return (NULL);
	}
	while (tmp)
	{
			printf("New path to add\n");
			print_path(tmp);
			add_new_paths(l, new_paths, tmp);
			tmp = tmp->next;
	}
	return (new_paths);
}
