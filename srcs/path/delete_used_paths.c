#include "lem_in.h"

t_path *delete_used_paths(t_pathlist *paths, t_path *finished)
{
	t_path *tmp;
	t_node *node;

	tmp = paths->start;
	while (tmp)
	{
		if (tmp != finished && !tmp->ended)
		{
			node = tmp->nodes->start;
			while (node)
			{
				if (!node->nb && check_nodelist(finished->nodes, node->nb))
				{
					return (delete_path(paths, tmp));
					break ;
				}
				node = node->next;
			}
		}
		tmp = tmp->next;
	}
	return (tmp);
}
