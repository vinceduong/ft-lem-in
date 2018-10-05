#include "lem_in.h"

void sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2))
{
	t_path 			*tmp;
	t_path			*tmpsort1;
	t_path 			*tmpsort2;

	ft_putstr("In sort_path\n");
	tmp = paths->start;
	while (tmp->next)
	{
		if (comp(tmp, tmp->next))
		{
			if (tmp == paths->start)
			{
				tmpsort1 = tmp->next;
				tmpsort1->previous = NULL;
				tmpsort2 = tmpsort1->next;
				tmpsort1->next = tmp->next;
				tmp->next = tmpsort2;
				tmp->previous = tmpsort1;
				paths->start = tmpsort1;
			}
			tmp = paths->start;
		}
		else
			tmp = tmp->next;
	}
}
