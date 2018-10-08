#include "lem_in.h"

t_pathlist *delete_used_paths(t_pathlist *paths, t_path *finished)
{
	t_path *tmp;
	t_node *node;
	int		 deleted;

	tmp = paths->start;
	while (tmp)
	{
		if (tmp != finished && !tmp->ended && finished->nodes->length <= tmp->nodes->length)
		{
			deleted = 0;
			node = tmp->nodes->start;
			while (node)
			{
				if (!node->nb && check_nodelist(finished->nodes, node->nb))
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
	return (paths);
}
