#include "lem_in.h"

void swap(t_pathlist **paths, t_path **a, t_path **b)
{
	t_path *next = NULL;
	t_path *prev = NULL;
	t_path *tmp;

	print_path(*a);
	print_path(*b);
	if (!(*a)->previous)
	{
		ft_putstr("Ici\n");
		(*paths)->start = *b;
		(*a)->previous = *b;
		(*a)->next = (*b)->next;
		(*b)->next = *a;
		(*b)->previous = NULL;
	}
	else
	{
		ft_putstr("La\n");
		next = (*a)->next;
		ft_putstr("La1\n");
		prev = (*a)->previous;
		ft_putstr("La2\n");
		printf("*a = %p\n", *a);
		printf("*b = %p\n", *b);
		tmp = (*b);
		(*a)->next = (*b)->next;
		ft_putstr("La3\n");
		printf("*a = %p\n", *a);
		printf("*b = %p\n", tmp);
		tmp->next = *a;
		ft_putstr("La4\n");
		(*a)->previous = *b;
		ft_putstr("La5\n");
		tmp->previous = prev;
	}

	/*
	if (tmpsort2->next)
	tmpnext = tmpsort2->next;
	if (tmpsort2->previous)
	tmpprevious = tmpsort2->previous;
	tmpsort2->next = tmpsort1;
	tmpsort2->previous = tmpsort1->previous;
	if (!tmpsort1->previous)
	paths->start = tmpsort2;
	tmpsort1->next = tmpnext;
	tmpsort1->previous = tmpprevious;
	*/
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

			ft_putstr("in if comp\n");
			swap(&paths, &tmp, &(tmp->next));
			tmp = paths->start;
			/*print_path(tmp);
			print_path(tmp->next);*/
		}
		tmp = tmp->next;
	}
	ft_putstr("Sort finished\n");
}
