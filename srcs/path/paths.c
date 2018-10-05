#include "lem_in.h"


t_pathlist *findpathlist(t_lemin *l, t_pathlist *paths)
{
	t_path *path;
	int notfinished = 0;
	t_path *tmp;
	if (!paths->start)
	{
		ft_putstr("In if !paths->start\n");
		if (!(path = new_path(NULL, 0)))
		{
			ft_putstr("new_path failed\n");
			return (NULL);
		}
		add_path(paths, path);
		l->m.graph[0][0] = 1;
		ft_putstr("add_path worked\n");
		print_path(path);
	}
	else
	{
		ft_putstr("In path start exist\n");
		if (!(paths = update_paths(l, paths)))
			return (NULL);

		tmp = paths->start;
		while (tmp)
			{
				if (!tmp->ended)
				{
					notfinished = 1;
					print_path(tmp);
					ft_putstr("NOT ENDED\n");
					break ;
				}
				tmp = tmp->next;
			}
			if(!notfinished)
			{
				ft_putstr("ALL ENDED\n");
				return (paths);

			}
	}
	print_path_list(paths);
	return (findpathlist(l, paths));
}


int 	paths(t_lemin *l)
{
		t_pathlist	*paths;

		print_matrix(l);

		if (!(paths = init_pathlist()))
		{
			ft_putstr("init_pathlist failed\n");
			return (0);
		}
		if (!(paths = findpathlist(l, paths)))
		{
			ft_putstr("find_pathlist failed\n");
			return (0);
		}
		if (!(fill_paths(l, paths)))
		{
			ft_putstr("fill_paths failed\n");
			return (0 );
		}
		return (1);
}
