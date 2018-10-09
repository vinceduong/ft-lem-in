#include "lem_in.h"
void free_node(t_node *node)
{
	ft_putstr("In free_node\n");

	if (node)
		free(node);
}

void free_nodelist(t_nodelist *nodelist)
{
	t_node *tmp;
	t_node *tmp2;

	ft_putstr("In free_nodelist\n");

	if (nodelist)
	{
		tmp = nodelist->start;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free_node(tmp2);
		}
		free(nodelist);
	}
}

void free_path(t_path *path)
{
	ft_putstr("In free_path\n");

	if (path)
	{
		free_nodelist(path->nodes);
		free(path);
	}
}

void free_pathlist(t_pathlist *pathlist)
{
	t_path *tmp;
	t_path *tmp2;

	if (pathlist)
	{
		tmp = pathlist->start;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free_path(tmp2);
		}
	}
}
