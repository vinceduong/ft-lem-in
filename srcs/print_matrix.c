#include "lem_in.h"
void print_matrix(t_lemin *l)
{
	int i = 0;
	int j = 0;
	printf (" ");
	while (i < l->m.nbcases)
	{
		printf (" %d ", i);
		i++;
	}
	printf ("\n");
	i = 0;
	while (i < l->m.nbcases)
	{
		j = 0;
		printf ("%d", i);
		while (j < l->m.nbcases)
		{
			printf("|%d|", l->m.graph[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}


void print_ant_road(t_lemin *lemin)
{
	int n;

	n = 0;
	while (n++ < lemin->nbpaths)
	{
		printf("%d\n", lemin->a.rep[n][0]);
	}
}
