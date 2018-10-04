#include "lem_in.h"

int					check_nodelist(t_nodelist *nodelist, int nodenb)
{
	t_node *tmp;

	tmp = nodelist->start;
	while (tmp)
	{
		if (tmp->nb == nodenb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
