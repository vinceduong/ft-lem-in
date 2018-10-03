#include "lem_in.h"


int findpathlist(t_lemin *l, t_nodelist *nl, t_nodelist *bl, t_pathlist *paths)
{
	t_path *path;

	if (!paths->start)
	{
		path = new_path(NULL, 0);
		add_path(paths, path);
	}
	else
	{
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

		if (!(paths = init_pathlist()))
			return (0 );
		if (!(nl = init_nodelist()))
			return (0);
		if (!(bl = init_nodelist()))
			return (0);
		if (!findpathlist(l, nl, bl, paths))
			return (0);
		if (!(array = list_to_sorted_array(paths)))
			return (0);
		l->p = array;
		return (1);
}
