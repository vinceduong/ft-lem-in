#include "lem_in.h"

void sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2))
{
	t_path 			*tmp;
	t_path			*tmpsort;

	tmp = paths->start;
	while (tmp->next)
	{
		if (comp(tmp, tmp->next))
		{
			tmpsort = tmp->next->next;
			tmp->next->next = tmp->next;
			tmp->next = tmpsort;
			tmpsort = tmp->next->previous;
			tmp->next->previous = tmp->previous;
			tmp->previous = tmpsort;
			tmp = paths->start;
		}
		else
			tmp = tmp->next;
	}
}
