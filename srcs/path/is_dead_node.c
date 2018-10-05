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
		else if (!(l->m.graph[i][i] == -1 || l->m.graph[i][i] == 2)
		&& l->m.graph[node][i] == 1 && !is_dead_node(l, i))
			nb_valid_nodes++;
		i++;
	}
	l->m.graph[node][node] = (nb_valid_nodes > 0 ? 2 : -1);
	return (nb_valid_nodes == 0);
}
