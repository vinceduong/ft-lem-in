#include "lem_in.h"

t_nodelist *cpy_nodelist(t_nodelist *src)
{
	t_nodelist	*dest;
	t_node 			*tmp;

	dest = (t_nodelist*)malloc(sizeof(t_nodelist));
	tmp = src->start;
	while (tmp)
	{
		add_node(dest, new_node(tmp->nb));
		tmp = tmp->next;
	}
	return (dest);
}

t_node		*new_node(int nb)
{
	t_node *new;

	new = (t_node*)malloc(sizeof(t_node));
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_nodelist	*add_node(t_nodelist *nodelist, t_node *node)
{
	t_node	*tmp;
	int			i;

	tmp = nodelist->start;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	node->index = i;
	tmp->next = node;
	nodelist->length++;
	return (nodelist);
}

int					check_nodelist(t_nodelist *nodelist, int nodenb)
{
	t_node *tmp;

	tmp = nodelist->start;
	while (tmp != NULL)
	{
		if (tmp->nb == nodenb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void					update_bl(t_nodelist *bl, t_path *path)
{
	t_node *tmp;

	tmp = path->nodes->start;
	while (tmp)
	{
		if (!check_nodelist(bl, tmp->nb))
			add_node(bl, new_node(tmp->nb));
		tmp = tmp->next;
	}
}
