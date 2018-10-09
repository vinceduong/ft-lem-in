#include "lem_in.h"

void	map_dead_nodes(t_lemin *l)
{
	int		i;
	int		j;
	int		count;
	int		ended;

	ended = 1;
	i = 0;
	while (i < l->m.nbcases)
	{
		j = 0;
		count = 0;
		if (i && i != l->m.nbcases - 1 && l->m.graph[i][i] != -1)
		{
			while (j < l->m.nbcases)
			{
				count += l->m.graph[i][j] && (l->m.graph[j][j] != -1) ? 1 : 0;
				j++;
			}
			if (count < 2)
			{
				l->m.graph[i][i] = -1;
				ended = 0;
			}
		}
		i++;
	}
	if (!ended)
		map_dead_nodes(l);
	return ;

}
