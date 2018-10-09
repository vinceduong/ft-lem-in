#include "lem_in.h"

int	count_new_childs(t_lemin *l, t_path *p)
{
	int count;
	int i;

	i = 0;
	count = 0;
	print_matrix(l);
	printf("Current node = %d\n", p->curr);
	while (i < l->m.nbcases)
	{
		if (l->m.graph[p->curr][i] && !l->m.graph[i][i])
		{
			count++;
			printf ("\t%d is a new child!\n", i);
		}
		i++;
	}
	printf("\tNode %d has %d new childs\n", p->curr, count);
	p->childs = count;
	return (count ? 1 : 0);
}
