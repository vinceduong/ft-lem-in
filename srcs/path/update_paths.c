#include "lem_in.h"

int compare_childs(t_path *p1, t_path *p2)
{
	if (!p1->ended && !p2->ended)
		return (p1->childs > p2->childs);
	return (0);
}

t_pathlist	*update_paths(t_lemin *l, t_pathlist *paths)
{
	ft_putstr("In update_path\n");
	t_path *tmp;
	int		 ended;
	t_pathlist *newlist;
	ended = 1;
	tmp = paths->start;
	//print_path_list(paths);
	printf("---------START WHILE IN UPDATE_PATH---------\n");
	while (tmp)
	{
		if (!tmp->ended && !count_new_childs(l, tmp))
		{
			ft_putstr("No childs\n");
			tmp = delete_path(paths, tmp);
			ft_putstr("Path deleted");
		}
		else if (!tmp->ended)
		{
			ended = 0;
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	printf("---------END WHILE IN UPDATE_PATH---------\n");
	print_path_list(paths);
	if (!paths->start)
		return (NULL);
	if (ended)
		return (paths);
	//sort_paths(paths, compare_childs);
	ft_putstr("sort_paths worked\n");
	if (!(newlist = new_path_list(l, paths)))
	{
		printf("faillist");
		return (0);
	}
	/*tmp = newlist->start;
	while (tmp)
	{
		if(tmp->ended)
			delete_used_paths(newlist, tmp);
		tmp = tmp->next;
	}*/
	paths = newlist;
	return (newlist);
}
