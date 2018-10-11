#include "lem_in.h"

int 	paths(t_lemin *l)
{
		t_pathlist	*paths;

		if (!(paths = init_pathlist()))
			return (0);
		map_dead_nodes(l);
		if (!(paths = find_pathlist(l, paths)))
			return (0);
		if (!(fill_paths(l, paths)))
			return (0);
		return (1);
}
