#include "lem_in.h"

int			check_ended(t_pathlist *pathlist)
{
	t_path *tmp;

	tmp = pathlist->start;
	while (tmp)
	{
		if (!tmp->ended)
			return (0);
		if (tmp->ended && tmp->nodes->length == 1)
			return (1);
		tmp = tmp->next;
	}
	return (1);
}

t_pathlist *find_pathlist(t_lemin *l, t_pathlist *paths)
{
	t_path *path;
	
	if (!paths->start)
	{
		if (!(path = new_path(NULL, 0)))
			return (NULL);
		add_path(paths, path);
		l->m.graph[0][0] = 1;
	}
	else
	{
		if (!(paths = update_paths(l, paths)))
			return (NULL);
		if(check_ended(paths))
			return (paths);
	}
	return (find_pathlist(l, paths));
}