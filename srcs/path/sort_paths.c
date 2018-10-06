#include "lem_in.h"

void swap(t_pathlist *paths, t_path *tmpsort1, t_path *tmpsort2)
{
	t_path *tmpnext;
	t_path *tmpprevious;

	tmpnext = tmpsort2->next;
	tmpprevious = tmpsort2->previous;
	tmpsort2->next = tmpsort1;
	tmpsort2->previous = tmpsort1->previous;
	if (!tmpsort1->previous)
		paths->start = tmpsort2;
	tmpsort1->next = tmpnext;
	tmpsort1->previous = tmpsort2;
}

void sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2))
{
	t_path 			*tmp;
	//t_path			*tmpsort1;
	//t_path 			*tmpsort2;

	ft_putstr("In sort_path\n");
	tmp = paths->start;
	while (tmp->next)
	{
		if (comp(tmp, tmp->next))
		{
				swap(paths, tmp, tmp->next);
				tmp = paths->start;
				print_path(tmp);
				print_path(tmp->next);
		}
		else
			tmp = tmp->next;
	}
}
