#include "lem_in.h"

#define STARTS l->m.starts_tunnels
#define END l->m.end_tunnels
#define NBCASES l->map.nbcases


int findpath(t_path path, t_map map, int curr, int *check)
{
	if (curr = map.nbcases)
		return (path;
}

int *init_check(nb)
{
	int *check;
	int i;

	if (!(check = (int *)malloc(nb * sizeof(int))))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		check[i] = 0;
		i++;
	}
	return (check);
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
