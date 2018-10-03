#include "lem_in.h"

t_nodelist	*add_node(t_nodelist *nodelist, t_node *node)
{
	t_node	*tmp;
	int			i;

	tmp = nodelist->start;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	node->index = i;
	tmp->next = node;
	nodelist->length++;
	return (nodelist);
}
