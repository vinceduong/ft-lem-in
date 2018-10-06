#include "lem_in.h"

int cpy_path(t_path *src, t_path *dest, t_node *node)
{
	ft_putstr("In cpy_path\n");
	dest->nodes = cpy_nodelist(src->nodes);
	ft_putstr("cpy_nodelist worked\n");
	dest->curr = src->curr;
	dest->ended = src->ended;
	if (node)
		add_node(dest->nodes, node);
	return (1);
}
