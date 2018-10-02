#include "lem_in.h"

int *cpyup_path(t_path *src, t_path *dest, int curr, t_node node)
{
	dest->nodes = cpy_nodelist(src->nodes);
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
	new->previous = NULL;
	return (new);
}

void		*add_path(t_path *pathlist, t_path *path)
{
	t_node	*tmp;
	int			i;

	tmp = *(pathlist->start);
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = path;
	path->previous = tmp;
	return (pathlist);
}

t_path *merge_paths(t_pathlist *paths, t_path *news, t_path *old)
{
	t_path *tmp_list;
	t_path *tmp_new;

	tmp_list = paths->start;
	tmp_new = news;
	while (tmp_list && tmp_list != old)
		tmp_list = tmp_list->next;
	tmp_list->previous->next = tmp_new;
	while (tmp_new->next)
		tmp_new = tmp_new->next;
	tmp_new->next = tmp_list->next;
	tmp_new->previous = tmp_list->previous;
	return (tmp_new->next);
}

t_path *delete_path(t_pathlist *paths, t_path *del)
{
	t_path *tmp;

	tmp = paths->start;
	while (tmp && tmp != del)
		tmp = tmp->next;
	if (tmp->previous)
		tmp->previous->next = tmp->next;
	if (tmp->next)
		tmp->next->previous = tmp->previous;
	return (tmp->next);
}
