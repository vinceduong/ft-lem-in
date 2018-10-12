#include "lem_in.h"

#define N	node->nb

void	delete_used_paths(t_pathlist *paths, t_path *finished, int end)
{
	t_path	*tmp;
	t_node	*node;
	int		deleted;

	tmp = paths->start;
	while (tmp)
	{
		deleted = 0;
		if (tmp != finished && (finished->nodes->length <= tmp->nodes->length))
		{
			node = tmp->nodes->start;
			while (node)
			{
				if (N != 0 && N != end && check_nodelist(finished->nodes, N))
				{
					tmp = delete_path(paths, tmp);
					deleted = 1;
					break ;
				}
				node = node->next;
			}
		}
		if (!deleted)
			tmp = tmp->next;
	}
}
