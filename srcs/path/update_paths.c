#include "lem_in.h"

int compare_childs(t_path *p1, t_path *p2)
{
	return (p1->childs > p2->childs);
}

t_pathlist	*update_paths(t_lemin *l, t_pathlist *paths)
{
	ft_putstr("In update_path\n");
	t_path *tmp;
	int		 ended;
	t_pathlist *newlist;
	ended = 0;
	tmp = paths->start;
	//print_path_list(paths);
	printf("---------START WHILE IN UPDATE_PATH---------\n");
	while (tmp)
	{
		if (!count_new_childs(l, tmp))
		{
			ft_putstr("No childs\n");
			tmp = delete_path(paths, tmp);
		}
		else
			tmp = tmp->next;
	}
	printf("---------END WHILE IN UPDATE_PATH---------\n");
	if (!paths->start)
		return (NULL);
	sort_paths(paths, compare_childs);
	ft_putstr("sort_paths worked\n");
	if (!(newlist = new_path_list(l, paths)))
	{
		printf("faillist");
		return (0);
	}
	paths = newlist;
	print_path_list(paths);

	return (newlist);
}
