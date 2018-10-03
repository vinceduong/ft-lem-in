#include "lem_in.h"

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
