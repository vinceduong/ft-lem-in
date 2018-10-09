#include "lem_in.h"

static int		ft_clean(int **lpath, int i)
{
	while (i)
		free(lpath[i--]);
	free(lpath);
	//exit(0);
	return (1);
}

static int		**ft_assign_tube(t_lemin *lemin, int i, int nbant)
{
	int j;

	j = -1;
	while (j++ != i)
		lemin->a.rep[j][1] += nbant;
	return (lemin->a.rep);
}

static int		ft_how_many(t_lemin *lemin, int ant, int length, int i)
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

int				ft_get_lost(t_lemin *lemin)
{
	int i;
	int value;

	value = 0;
	i = 0;
	while (i < lemin->nbpaths )
	{
		value += lemin->a.rep[i][1];
		i++;
	}
	return (value == lemin->a.nbants ? 0 : lemin->a.nbants - value);
}

int				**ft_last_assign(t_lemin *lemin, int i, int nbant)
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

static int		ft_last_ant(t_lemin *lemin, int nbant, int ant, int i)
{
	while (ant)
	{
		nbant = ft_how_many(lemin, ant, lemin->a.rep[i][0], i);
		if (nbant == 0)
			break ;
		lemin->a.rep = ft_assign_tube(lemin, i, nbant);
		ant -= (nbant * (i + 1));
	}
	nbant = ft_get_lost(lemin);
	lemin->a.rep = ft_last_assign(lemin, i, nbant);
	return (0);
}

static void		ft_assign_ant(t_lemin *lemin)
{
	int i;
	int ant;
	int nbant;

	i = 0;
	nbant = 0;
	ant = lemin->a.nbants;
	while (ant > 0)
	{
		if (i == lemin->nbpaths - 1)
			ant = ft_last_ant(lemin, nbant, ant, i);
		else
		{
			nbant = ft_how_many(lemin, ant, lemin->a.rep[i][0], i);
			lemin->a.rep = ft_assign_tube(lemin, i, nbant);
			i++;
		}
		ant -= nbant;
	}
}

static void		ft_get_length(t_lemin *lemin)
{
	int n;
	int i;

	n = 0;
	i = 0;
	if (!(lemin->a.rep = (int**)malloc(sizeof(int*) * lemin->nbpaths + 2)))
		exit (0);
	while (i < lemin->nbpaths)
	{
		lemin->a.rep[i] = (int*)malloc(sizeof(int) * 2);
		lemin->a.rep[i][0] = lemin->p[i].nodes->length;
		lemin->a.rep[i][1] = 0;
		lemin->a.rep[i][2] = 0;
		i++;
	}
}

static void		ft_attribute_ant(t_lemin *lemin)
{
	int n;
	int i;
	int j;
	int l;

	i = 0;
	while (i < lemin->nbpaths)
	{
		l = lemin->a.rep[i][1];
		j = lemin->a.rep[i][0];
		free(lemin->a.rep[i]);
		if (!(lemin->a.rep[i] = (int*)malloc(sizeof(int) * l + 2)))
			exit (0);
		lemin->a.rep[i][l + 2] = 0;
		lemin->a.rep[i][0] = l;
		i++;
	}
	n = 1;
	i = 0;
	j = 1;
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
	return (1);
}
