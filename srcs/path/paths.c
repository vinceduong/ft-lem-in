#include "lem_in.h"


t_pathlist *findpathlist(t_lemin *l, t_pathlist *paths)
{
	t_path *path;
	int notfinished = 0;
	t_path *tmp;
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

		tmp = paths->start;
		while (tmp)
			{
				if (!tmp->ended)
				{
					notfinished = 1;
					break ;
				}
				tmp = tmp->next;
			}
			if(!notfinished)
				return (paths);
	}
	return (findpathlist(l, paths));
}


int 	paths(t_lemin *l)
{
		t_pathlist	*paths;

		if (!(paths = init_pathlist()))
			return (0);
		map_dead_nodes(l);
		if (!(paths = findpathlist(l, paths)))
			return (0);
		if (!(fill_paths(l, paths)))
			return (0 );
		return (1);
}
