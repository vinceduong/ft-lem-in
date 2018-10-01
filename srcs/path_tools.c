#include "lem_in.h"

t_node		*new_path(t_path *path, int nodenb)
{
	t_path			p;
	t_path			*new;
	t_node			*node;
	t_nodelist 	nl;
	new = &node;
	if (!path)
	{
			new->nodes = nl;
			new->nodes.length = 0;
			new->nodes.start = ;
	}
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_nodelist	*add_path(t_nodelist *nodelist, t_node *node)
{
	t_node	*tmp;
	int			i;

	tmp = *(nodelist->start);
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	node->index = i;
	tmp->next = node;
	return (nodelist);
}

int					check_nodelist(t_nodelist *nodelist, int nodenb)
{
	t_node *tmp;

	tmp = *(nodelist->start);
	while (tmp != NULL)
	{
		if (tmp->nb == nodenb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
