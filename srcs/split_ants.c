#include "lem_in.h"

static int		ft_get_lost(t_lemin *lemin)
{
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (i < lemin->nbpaths)
	{
		value += lemin->a.rep[i][1];
		i++;
	}
	return (value == lemin->a.nbants ? 0 : lemin->a.nbants - value);
}

static int		ft_last_ant(t_lemin *lemin, int nbant, int ant, int i)
{
	while (ant)
	{
		nbant = ft_how_many(lemin, ant, i);
		if (nbant == 0)
			break ;
		lemin->a.rep = ft_last_assign(lemin, i, nbant);
		ant -= (nbant * (i + 1));
	}
	nbant = ft_get_lost(lemin);
	lemin->a.rep = ft_last_assign(lemin, i, nbant);
	return (0);
}

static void		ft_assign_ant(t_lemin *lemin)
{
	int		i;
	int		ant;
	int		nbant;

	i = 0;
	nbant = 0;
	ant = lemin->a.nbants;
	if (ant <= lemin->nbpaths)
	{
		while (i < lemin->nbpaths && ant-- > 0)
		{
			lemin->a.rep[i][1]++;
			i++;
		}
	}
	while (ant > 1)
	{
		if (i == lemin->nbpaths - 1)
			ant = ft_last_ant(lemin, nbant, ant, i);
		else
		{
			nbant = ft_how_many(lemin, ant, i);
			lemin->a.rep = ft_assign_tube(lemin, i, nbant);
			i++;
		}
		ant -= nbant;
	}
}

static void		ft_attribute_ant(t_lemin *lemin)
{
	int		n;
	int		i;
	int		j;

	n = 1;
	i = 0;
	j = 1;
	lemin->a.rep = ft_realloc_ant(lemin, i, 0);
	while (n - 1 < lemin->a.nbants)
	{
		if (i == lemin->nbpaths)
		{
			i = 0;
			j++;
		}
		if (j <= lemin->a.rep[i][0])
			lemin->a.rep[i][j] = n++;
		i++;
	}
}

int				split_ants(t_lemin *lemin)
{
	ft_get_length(lemin);
	ft_assign_ant(lemin);
	ft_attribute_ant(lemin);
	int i = 0;
	int n = 0;
	while (i < lemin->nbpaths)
	{
		n = 0;
		while (lemin->a.rep[i][n] != 0)
		{
			printf("%d |", lemin->a.rep[i][n]);
			n++;
		}
		printf("%d |", lemin->a.rep[i][n]);
		printf("\n");
		i++;
	}
	return (1);
}
