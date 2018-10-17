#include "lem_in.h"

#define NL nodes->length

void	fill_size(t_lemin *l, int **size_ants)
{
	int turn;
	int i;
	int nbants;

	nbants = l->a.nbants;
	turn = 0;
	while (nbants)
	{
		i = 0;
		while (i < l->nbpaths)
		{
			if (nbants && size_ants[i][0] <= turn)
			{
				size_ants[i][1]++;
				nbants--;
			}
			i++;
		}
		turn++;
	}
}

int		**size_ants(t_lemin *l)
{
	int **size_ants;
	int i;

	if (!(size_ants = (int **)malloc(sizeof(int *) * l->nbpaths)))
		return (NULL);
	i = 0;
	while (i < l->nbpaths)
	{
		if (!(size_ants[i] = (int *)malloc(sizeof(int *) * 2)))
			return (NULL);
		size_ants[i][0] = (i > 0 ? l->p[i]->NL - l->p[0]->NL : 0);
		size_ants[i][1] = 0;
		i++;
	}
	fill_size(l, size_ants);
	return (size_ants);
}

void	fill_ants(t_lemin *l, int **ants, int **size)
{
	int count_ant;
	int turn;
	int i;

	count_ant = 1;
	turn = 0;
	while (count_ant <= l->a.nbants)
	{
		i = 0;
		while (i < l->nbpaths)
		{
			if (count_ant <= l->a.nbants
			&& size[i][1] && ants[i][0] < size[i][1])
			{
				ants[i][ants[i][0] + 1] = count_ant;
				ants[i][0]++;
				count_ant++;
			}
			i++;
		}
	}
}

int		split_ants(t_lemin *l)
{
	int **ants;
	int **size;
	int i;

	if (!(size = size_ants(l)))
		return (0);
	i = 0;
	if (!(ants = (int **)malloc(sizeof(int *) * l->nbpaths)))
		return (0);
	i = 0;
	while (i < l->nbpaths)
	{
		if (!(ants[i] = (int *)malloc(sizeof(int *) * (size[i][1] + 2))))
			return (0);
		ants[i][0] = 0;
		ants[i][size[i][1] + 1] = 0;
		i++;
	}
	fill_ants(l, ants, size);
	l->a.rep = ants;
	ft_free_int(size, l->nbpaths);
	return (1);
}
