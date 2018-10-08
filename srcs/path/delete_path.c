#include "lem_in.h"

t_path *delete_path(t_pathlist *paths, t_path *del)
{
	t_path *tmp;

	ft_putstr("In delete_path\n");
	tmp = paths->start;
	if (tmp == del)
	{
		tmp->previous = NULL;
		return (paths->start = tmp->next);
	}
	while (tmp->next && tmp->next != del)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	tmp->next->next->previous = tmp;
	if (tmp->next)
		tmp->next->previous = tmp;
	return (tmp->next);
}
