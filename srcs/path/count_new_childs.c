#include "lem_in.h"

int	count_new_childs(t_lemin *l, t_path *p)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < l->m.nbcases)
	{
		if (l->m.graph[p->curr][i] && l->m.graph[i][i] == 0)
			count++;
		i++;
	}
	p->childs = count;
	return (count ? 1 : 0);
}
