#include "lem_in.h"

t_node		*new_path(t_path *path)
{
	t_path			*new;

	new = (t_path*)malloc(sizeof(t_path));
	if (!path)
	{
			new->nodes = (t_nodelist*)malloc(sizeof(t_path));
			new->ended = 0;
			new->curr = 0;
	}
	else
	{
		new->ended = path->ended;
		new->nodes = path->nodes;
		new->curr = path->curr;

	}
	new->next = NULL;
	return (new);
}

t_nodelist	*add_path(t_path *path, t_path *newpath, t_node *node)
{
	t_path	*tmp;
	int			i;

	tmp = path;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = newpath;
	newpath->curr = node->nb;
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

void inject_paths(t_path *srcs, t_path *dest)
