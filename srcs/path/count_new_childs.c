#include "lem_in.h"

int	count_new_childs(t_lemin *l, t_nodelist *nl, t_path *p)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < l->m.nbcases)
	{
		if (i && l->m.graph[p->curr][i] != 0 && check_nodelist(nl, i))
			count++;
		i++;
	}
	p->childs = count;
	return (1);
}
