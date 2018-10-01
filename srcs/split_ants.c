#include "lem_in.h"

int 		**ft_length_of_each_path(t_lemin *lemin, int **lengthpath)
{
	t_nodelist *i;
	t_node *f;
	int ipath;

	f = i->start;
	ipath = 0;
	lengthpath = (int**)malloc(sizeof(int*) * lemin->p->nbpath);
	while (f->next != NULL)
	{
		lengthpath[ipath] = (int*)malloc(sizeof(int*) * f->nb);
		f = f->next;
		ipath++;
	}
	return (lengthpath);
}

static void ft_multipath(t_lemin *lemin, int **lengthpath, int path, int ant)
{
	t_nodelist *f;
	t_node *i;
	int iant;

	f = i->start;
	iant = 0;
	while (f->next != NULL)
	{
		lemin->a->rep[path] = (int*)malloc(sizeof(int) * f->length + 1);
		f = f->next;
		path++;
	}
	path = 0;
	while (ant < lemin->a->nbants)
	{
		lemin->a->rep[path++][iant] = ant;
		if (path == lemin->p->nbpath)
		{
			iant++;
			path = 0;
		}
		ant++;
	}
}

int split_ants(t_lemin *lemin)
{
	int **lengthpath;
	int ant;

	lengthpath = 0;
	ant = 0;
	lemin->a->rep = (int**)malloc(sizeof(int*) * lemin->p->nbpath);
	if (lemin->p->nbpath == 1)
	{
		lemin->a->rep[0] = (int*)malloc(sizeof(int) * lemin->a->nbants + 1);
		while (ant < lemin->a->nbants)
			lemin->a->rep[0][ant] = ant++;
		lemin->a->rep[0][ant] = 0;
	}
	else
	{
		lengthpath = ft_length_of_each_path(lemin, lengthpath);
		ft_multipath(lemin, lengthpath, 0, ant);
	}
}
