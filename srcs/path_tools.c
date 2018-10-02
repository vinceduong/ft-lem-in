#include "lem_in.h"

t_path *init_path(void)
{
	t_path *p;

	if (!(p = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	p->curr = 0;
	p->childs = 0;
	if (!(p->nodes = init_nodelist()))
		return (NULL);
	p->ended = 0;
	p->next = NULL;
	p->previous = NULL;
	return (p);
}

t_pathlist *init_pathlist()
{
	t_pathlist *pl;

	if (!(pl = (t_pathlist *)malloc(sizeof(t_pathlist))))
		return (NULL);
	return (pl);
}

int cpy_path(t_path *src, t_path *dest, t_node *node)
{
	dest->nodes = cpy_nodelist(src->nodes);
	dest->curr = src->curr;
	dest->ended = src->ended;
	add_node(dest->nodes, node);
	return (1);
}

t_path		*new_path(t_path *path, int nodenb)
{
	t_path			*new;
	t_node			*node;
	t_nodelist 	*nl;

	node = new_node(nodenb);
	if (!(new = init_path()))
		return (NULL);
	if (!(nl = init_nodelist()))
		return (NULL);
	if (!path)
	{
			new->curr = nodenb;
			add_node(nl, node);
			new->nodes = nl;
			new->ended = 0;
	}
	else
		cpy_path(path, new, node);
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void		*add_path(t_pathlist *pathlist, t_path *path)
{
	t_path	*tmp;

	tmp = pathlist->start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = path;
	path->previous = tmp;
	return (pathlist);
}

t_path *merge_paths(t_pathlist *paths, t_pathlist *news, t_path *old)
{
	t_path *tmp_list;
	t_path *tmp_new;

	tmp_list = paths->start;
	tmp_new = news->start;
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
