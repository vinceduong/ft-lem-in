#include "lem_in.h"

#define STARTS l->m.starts_tunnels
#define END l->m.end_tunnels
#define NBCASES l->map.nbcases


t_path findpath(t_path path, t_map map, int curr, int *check)
{
	int i;
	int *newcheck;

	if (curr = map.nbcases)
		return (path);
	i = 0;

	while (i < map.nbcases)
	{
		if (map.graph[curr][i] && i != curr)
		{
			if (!(newcheck = cpycheck(check)))
				return (0);
			newcheck[i] = 1;
			if (!add_case(path, i))
				return (0);
			return (findpath(path,))
		}
	}
}

int	findallpath(t_lemin *l)
{
		t_path	*path;
		int			i;
		int			curr;
		int			*check;

		i = 0;
		curr = 0;
		if (!(check = init_check(NBCASES))
			return (NULL);
		while (curr != NBCASES)
		{

		}
		return (1);
}

int	path(t_lemin *l)
{
	int max;
	int nbpaths;

	max = (STARTS < END ? STARTS : ENDS);
	nbpaths = 0;
	while (nbpaths < max)
	{
		if (!findpath(l))
			break ;
		nbpath++;
	}
	if (!nbpath)
		return (0);
	l->nbpaths = nbpaths;
	return (1);
}
