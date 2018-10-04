#include "lem_in.h"


int findpathlist(t_lemin *l, t_pathlist *paths)
{
	t_path *path;

	if (!paths->start)
	{
		ft_putstr("In if !paths->start\n");
		if (!(path = new_path(NULL, 0)))
		{
			ft_putstr("new_path failed\n");
			return (0);
		}
		add_path(paths, path);
		l->m.graph[0][0] = 1;
		ft_putstr("add_path worked\n");
		print_path(path);
	}
	else
	{
		ft_putstr("In path start exist\n");
		if (!update_paths(l, paths))
			return (1);
	}
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
		if (!findpathlist(l, paths))
		{
			ft_putstr("find_pathlist failed\n");
			return (0 );
		}
		if (!(fill_paths(l, paths)))
		{
			ft_putstr("fill_paths failed\n");
			return (0 );
		}
		return (1);
}
