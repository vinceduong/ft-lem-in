#include "lem_in.h"

void	delete_used_paths(t_pathlist *paths, t_path *finished, int end)
{
	t_path *tmp;
	t_node *node;
	int		 deleted;

	tmp = paths->start;
	deleted = 0;
	while (tmp)
	{
		deleted = 0;
		if (tmp != finished && (finished->nodes->length <= tmp->nodes->length || !tmp->ended))
		{
			node = tmp->nodes->start;
			while (node)
			{
				if (node->nb != 0 && node->nb != end && check_nodelist(finished->nodes, node->nb))
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
