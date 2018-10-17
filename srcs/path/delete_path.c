#include "lem_in.h"

t_path	*delete_path(t_pathlist *paths, t_path *del)
{
	t_path *tmp;

	tmp = paths->start;
	if (tmp == del)
	{
		if (tmp->next)
		{
			tmp->next->previous = NULL;
			paths->start = tmp->next;
		}
		else
			paths->start = NULL;
		free_path(del);
		return (paths->start);
	}
	while (tmp->next && tmp->next != del)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	if (tmp->next)
	{
		tmp->next->previous = tmp;
		tmp->next->next ? tmp->next->next->previous = tmp : 0;
	}
	free_path(del);
	return (tmp->next);
}
