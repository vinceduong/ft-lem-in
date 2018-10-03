#include "lem_in.h"

int cpy_path(t_path *src, t_path *dest, t_node *node)
{
	dest->nodes = cpy_nodelist(src->nodes);
	dest->curr = src->curr;
	dest->ended = src->ended;
	add_node(dest->nodes, node);
	return (1);
}
