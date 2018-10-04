#include "lem_in.h"

int	count_new_childs(t_lemin *l, t_nodelist *nl, t_path *p)
{
	int count;
	int i;

	i = 0;
	count = 0;
	printf("nbcases  = %d\n", l->m.nbcases);
	while (i < l->m.nbcases)
	{
		if (l->m.graph[p->curr][i])
			printf ("%d can be ur fucking child\n", i);
		if (l->m.graph[p->curr][i] && !check_nodelist(nl, i))
		{
			count++;
			printf ("You have child %d!\n", i);
		}
		printf("i = %d\n", i);
		i++;
	}
	printf("Node %d has %d new childs\n", p->curr, count);
	p->childs = count;
	return (count ? 1 : 0);
}
