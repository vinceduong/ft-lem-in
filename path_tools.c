#include "lem_in.h"

int *cpyup_path(t_path *src, t_path *dest, int curr, t_node node)
{
	dest->nodes = src->nodes;
	dest->curr = curr;
	dest->ended = src->ended;
	add_node(dest->nodes, node);
}

t_node		*new_path(t_path *path, int nodenb)
{
	t_path			*new;
	t_node			*node;
	t_nodelist 	nl;

	new = (t_path *)malloc(sizeof(t_path));
	node = new_node(nodenb);
	if (!path)
	{
			new->curr = nodenb;
			new->nodes = nl;
			new->nodes.length = 1;
			new->nodes.start = node;
			new->ended = 0;
	}
	else
		cpyup_path(t_path *src, t_path *dest);
	new->next = NULL;
	return (new);
}

t_nodelist	*add_path(t_pathlist *pathlist, t_path *path)
{
	t_node	*tmp;
	int i;

	tmp = *(pathlist->start);
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = path;
	return (pathlist);
}

int					check_nodelist(t_nodelist *nodelist, int nodenb)
{
	t_node *tmp;

	tmp = nodelist->start;
	while (tmp)
	{
		if (tmp->nb == nodenb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
