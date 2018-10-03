#include "lem_in.h"

t_nodelist *cpy_nodelist(t_nodelist *src)
{
	t_nodelist	*dest;
	t_node 			*tmp;

	dest = (t_nodelist*)malloc(sizeof(t_nodelist));
	tmp = src->start;
	while (tmp)
	{
		add_node(dest, new_node(tmp->nb));
		tmp = tmp->next;
	}
	return (dest);
}
