#include "lem_in.h"


int findpathlist(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths)
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
		add_node(nl, new_node(0));
		ft_putstr("add_path worked\n");
	}
	else
	{
		ft_putstr("In path start exist\n");
		if (!update_paths(l, nl, bl, paths))
			return (0);
	}
	return (findpathlist(l, nl, bl, paths));
}


int 	paths(t_lemin *l)
{
		t_nodelist	*nl;
		t_nodelist	*bl;
		t_pathlist	*paths;
		t_path			*array;

		/*Limit testing*/
		int i = 0;
		int j = 0;
		while (i < l->m.nbcases)
		{
			j = 0;
			while (j < l->m.nbcases)
			{
				printf("|%d|", l->m.graph[i][j]);
				j++;
			}
			i++;
			printf("\n");
		}
		/*End of limit testing*/
		if (!(paths = init_pathlist()))
		{
			ft_putstr("init_pathlist failed\n");
			return (0);
		}
		if (!(nl = init_nodelist()))
		{
			ft_putstr("init_nodelist nl failed\n");
			return (0 );
		}
		if (!(bl = init_nodelist()))
		{
			ft_putstr("init_pathlist bl failed\n");
			return (0 );
		}
		if (!findpathlist(l, nl, bl, paths))
		{
			ft_putstr("find_pathlist failed\n");
			return (0 );
		}
		if (!(array = list_to_sorted_array(paths)))
		{
			ft_putstr("list_to_sorted_array failed\n");
			return (0 );
		}
		l->p = array;
		return (1);
}
