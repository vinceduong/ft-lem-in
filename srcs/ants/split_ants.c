#include "lem_in.h"

int **size_ants(t_lemin *l)
{
	int **size_ants;
	int nbants;
	int i;
	int turn;

	if (!(size_ants = (int **)malloc(sizeof(int *) * l->nbpaths)))
		return (NULL);
	nbants = l->a.nbants;
	i = 0;
	while (i < l->nbpaths)
	{
		if (!(size_ants[i] = (int *)malloc(sizeof(int *) * 2)))
			return (NULL);
		size_ants[i][0] = (i > 0 ? l->p[i].nodes->length - l->p[0].nodes->length : 0);
		size_ants[i][1] = 0;
//		printf("size_ants[%d][0] = %d, size_ants[%d][1] = %d\n", i, size_ants[i][0], i, size_ants[i][1]);
		i++;
	}
	ft_putstr("ok1\n");
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
	return (size_ants);
}

void fill_ants(t_lemin *l, int **ants, int **size)
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
			if (count_ant <= l->a.nbants && size[i][1] && ants[i][0] < size[i][1])
			{
				ants[i][ants[i][0] + 1] = count_ant;
//				printf("i = %d, count_ant = %d\n", i, count_ant);
				ants[i][0]++;
				count_ant++;
			}
			i++;
		}
		
	}
}

int split_ants(t_lemin *l)
{
	int **ants;
	int **size;
	int i;

	if (!(size = size_ants(l)))
		return (0);
	//printf("size_ants worked\n");
	i = 0;
	while (i < l->nbpaths)
	{
//		print_path(&l->p[i]);
		i++;
	}
	if (!(ants = (int **)malloc(sizeof(int *) * l->nbpaths)))
		return (0);
	i = 0;
	while (i < l->nbpaths)
	{
		if (!(ants[i] = (int *)malloc(sizeof(int *) * (size[i][1] + 2))))
			return (0);
		ants[i][0] = 0;;
		ants[i][size[i][1] + 1] = 0;
		i++; 
	}
	fill_ants(l, ants, size);
	i = 0;
	int j;
	while (i < l->nbpaths)
	{
		j = 0;
		printf("ants[%d] = ", i);
		while (ants[i][j])
		{
			printf("|%d|", ants[i][j]);
			j++;
		}
		printf("\n");
		i++;
		
	}
	l->a.rep = ants;
	return (1);
}