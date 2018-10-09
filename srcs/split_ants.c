#include "lem_in.h"

static int ft_clean(int **lpath, int i)
{
	while (i)
		free(lpath[i--]);
	free(lpath);
	//exit(0);
	return (1);
}

void print_path_ant(t_lemin *lemin)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (i++ < lemin->nbpaths - 1)
		printf("PATH %d == %d\n", i, lemin->a.rep[i][1]);
}

static int **ft_assign_tube(t_lemin *lemin, int i, int nbant)
{
	int j;

	j = -1;
	printf("nb ant = %d\n", nbant);
	while (j++ != i)
		lemin->a.rep[j][1] += nbant;
	return (lemin->a.rep);
}

static int ft_how_many(t_lemin *lemin, int ant, int length, int i)
{
	int value;

	value = 0;
	if (lemin->a.rep[0][0] == 0)
		return (ant);
	else if (i == lemin->nbpaths - 1)
	{
		printf("ant = %d\n", ant);
		value = ant / (i + 1);
	}
	else
		value = lemin->a.rep[i + 1][0] - lemin->a.rep[i][0];
	return (value);
}

int ft_get_lost(t_lemin *lemin)
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

int **ft_last_assign(t_lemin *lemin, int i, int nbant)
{
	int j;

	j = -1;
	printf("%d\n", nbant);
	while (nbant > 0)
	{
		j == i ? j = 0 : j++;
		lemin->a.rep[j][1]++;
		nbant--;
	}
	return (lemin->a.rep);
}

static void ft_assign_ant(t_lemin *lemin)
{
	int i;
	int ant;
	int nbant;

	i = 0;
	nbant = 0;
	ant = lemin->a.nbants;
	printf("HOW MANY PATH %d\n", lemin->nbpaths);
	while (ant)
	{
		if (i == lemin->nbpaths - 1)
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
			ant = 0;
			break ;
		}
		else
		{
			nbant = ft_how_many(lemin, ant, lemin->a.rep[i][0], i);
			lemin->a.rep = ft_assign_tube(lemin, i, nbant);
			i++;
		}
		ant -= nbant;
	}
}

static void ft_get_length(t_lemin *lemin)
{
	int n;
	int i;

	n = 0;
	i = 0;
	if (!(lemin->a.rep = (int**)malloc(sizeof(int*) * lemin->nbpaths + 1)))
		exit (0);
	while (i != lemin->nbpaths)
	{
		lemin->a.rep[i] = (int*)malloc(sizeof(int) * 2);
		lemin->a.rep[i][0] = lemin->p[i].nodes->length;
		lemin->a.rep[i][1] = 0;
		lemin->a.rep[i][2] = 0;
		i++;
	}
}

int split_ants(t_lemin *lemin)
{
	ft_get_length(lemin);
	ft_assign_ant(lemin);
	print_path_ant(lemin);
	return (1);
}

/*98 - 95 - 79 - 40
 x / n = xf
98
4 = 3 + 8 + 13 + 10 == 	34
7 = 8 + 13 + 10 == 		31
15 = 13 + 10 == 		23
38 = 10 = 				10
*/
