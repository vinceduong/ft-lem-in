#include "lem_in.h"

void swap(t_path **a, t_path **b)
{
	int tmpcurr;
	int tmpchilds;
	t_nodelist *tmpnodes;
	int tmpended;

	tmpcurr = (*b)->curr;
	tmpchilds = (*b)->childs;
	tmpnodes = (*b)->nodes;
	tmpended = (*b)->ended;

	(*b)->curr = (*a)->curr;
	(*b)->childs = (*a)->childs;
	(*b)->nodes = (*a)->nodes;
	(*b)->ended = (*a)->ended;

	(*a)->curr = tmpcurr;
	(*a)->childs = tmpchilds;
	(*a)->nodes = tmpnodes;
	(*a)->ended = tmpended;
}

void sort_paths(t_pathlist *paths, int (*comp)(t_path *p1, t_path *p2))
{
	t_path 			*tmp;
	t_path			*tmpsort;
	//t_path			*tmpsort1;
	//t_path 			*tmpsort2;

	ft_putstr("In sort_path\n");
	tmp = paths->start;
	while (tmp->next)
	{
		if (comp(tmp, tmp->next))
		{

			ft_putstr("in if comp\n");
			tmpsort = tmp->next;
			swap(&tmp, &tmpsort);
			tmp = paths->start;
			/*print_path(tmp);
			print_path(tmp->next);*/
		}
		tmp = tmp->next;
	}
	ft_putstr("Sort finished\n");
}
