#include "lem_in.h"

int is_dead_node(t_lemin *l, int node)
{
	int i;
	int nb_valid_nodes;

	i = 0;
	ft_printf("In dead_node , node = %d\n", node);
	nb_valid_nodes = 0;
	l->m.graph[node][node] = 2;
	while (i < l->m.nbcases)
	{
		if (i == l->m.nbcases - 1)
			return (0);
		if (node != i && l->m.graph[node][node] != 2 && !is_dead_node(l, i))
		{
			printf("Is_valid\n");
			nb_valid_nodes++;
		}
		i++;
	}
	printf("curr = %d, nb_valid_nodes = %d\n", node, nb_valid_nodes);
	l->m.graph[node][node] = (nb_valid_nodes > 0 ? 2 : -1);
	return (nb_valid_nodes == 0);
}
