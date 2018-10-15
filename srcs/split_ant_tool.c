#include "lem_in.h"

void		ft_get_length(t_lemin *lemin)
{
	int n;
	int i;

	n = 0;
	i = 0;
	if (!(lemin->a.rep = (int**)malloc(sizeof(int*) * lemin->nbpaths)))
		exit(0);
	while (i < lemin->nbpaths)
	{
		lemin->a.rep[i] = (int*)malloc(sizeof(int) * 1);
		lemin->a.rep[i][0] = lemin->p[i].nodes->length;
		lemin->a.rep[i][1] = 0;
		lemin->a.rep[i][2] = 0;
		i++;
	}
}

int			**ft_realloc_ant(t_lemin *lemin, int i, int l, int j)
{
	while (i < lemin->nbpaths)
	{
		l = lemin->a.rep[i][1];
		free(lemin->a.rep[i]);
		if (!(lemin->a.rep[i] = (int*)malloc(sizeof(int) * l + 2)))
			exit(0);
		lemin->a.rep[i][l + 1] = 0;
		lemin->a.rep[i][0] = l;
		i++;
	}
	return (lemin->a.rep);
}

int			ft_how_many(t_lemin *lemin, int ant, int i)
{
	int value;

	value = 0;
	if (lemin->a.rep[0][0] == 0)
		return (ant);
	else if (i == lemin->nbpaths - 1)
	{
		value = ant / (i + 1);
	}
	else
		value = lemin->a.rep[i + 1][0] - lemin->a.rep[i][0];
	return (value);
}

int			**ft_assign_tube(t_lemin *lemin, int i, int nbant)
{
	int j;

	j = -1;
	while (j++ < i + 1)
		lemin->a.rep[j][1] += nbant;
	return (lemin->a.rep);
}

int			**ft_last_assign(t_lemin *lemin, int i, int nbant)
{
	int j;

	j = -1;
	while (nbant > 0)
	{
		j == i ? j = 0 : j++;
		lemin->a.rep[j][1]++;
		nbant--;
	}
	return (lemin->a.rep);
}
