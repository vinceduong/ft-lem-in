#include "lem_in.h"

int *cpyup_path(t_path *src, t_path *dest, t_node node)
{
	dest->nodes = cpy_nodelist(src->nodes);
	dest->curr = src->curr;
	dest->ended = src->ended;
	add_node(dest->nodes, node);
}

t_node		*new_path(t_path *path, int nodenb)
{
	t_path			*new;
	t_node			*node;
	t_nodelist 	*nl;

	new = (t_path *)malloc(sizeof(t_path));
	node = new_node(nodenb);
	if (!path)
	{
			nl = (t_nodelist*)malloc(sizeof(t_nodelist));
			new->curr = nodenb;
			add_node(nl, node);
			new->nodes = nl;
			new->ended = 0;
	}
	else
		cpyup_path(t_path *src, t_path *dest, node));
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void		*add_path(t_path *pathlist, t_path *path)
{
	t_node	*tmp;
	int			i;

	tmp = pathlist->start;
	while (tmp->next)
		tmp = tmp->next;
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
	while (tmp_list->next && tmp_list->next != old)
		tmp_list = tmp_list->next;
	tmp_list->next = tmp_new;
	while (tmp_new->next)
		tmp_new = tmp_new->next;
	tmp_new->next = old->next;
	tmp_new->previous = tmp_list;
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
