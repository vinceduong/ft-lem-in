#include "lem_in.h"
# define R lemin->a.rep

size_t		ops_size(t_lemin *lemin)
{
	int i;
	int n;
	int max;

	i = 0;
	max = -1;
	while (i < lemin->nbpaths)
	{
		n = 0;
		n += lemin->a.rep[i][0];
		n += lemin->p[i].nodes->length;
		if (n > max)
			max = n;
		i++;
	}
	return (max + 1);
}

char		*step_writer(t_lemin *lemin, int antnum, t_node *room)
{
	char *tmp;
	char *itoa;

	itoa = ft_itoa(antnum);
	tmp = ft_strjoinfree(ft_strdup(" L"), itoa);
	free(itoa);
	tmp = ft_strjoinfree(tmp, "-");
	tmp = ft_strjoinfree(tmp, lemin->m.cases[room->nb]);
	return (tmp);
}

int			launch_path(t_lemin *lemin, int pathnumber)
{
	int			antpos;
	int			wave;
	t_node		*room;
	char		*step;

	antpos = 1;
	while (antpos <= lemin->a.rep[pathnumber][0])
	{
		wave = antpos - 1;
		room = lemin->p[pathnumber].nodes->start->next;
		while (room)
		{
			step = step_writer(lemin, lemin->a.rep[pathnumber][antpos], room);
			if (!lemin->r.ops[wave])
				lemin->r.ops[wave] = ft_strdup(step);
			else
				lemin->r.ops[wave] = ft_strjoinfree(lemin->r.ops[wave], step);
			room = room->next;
			wave++;
			free(step);
		}
		if (antpos + 1)
			antpos++;
	}
	return (1);
}

int			record(t_lemin *lemin)
{
	int	i;
	int ops_s;

	ops_s = ops_size(lemin);
	if (!(lemin->r.ops =
				(char **)malloc(ops_s * sizeof(char *))))
		return (0);
	i = 0;
	while (i < ops_s)
	{
		lemin->r.ops[i] = NULL;
		i++;
	}
	i = 0;
	while (i < lemin->nbpaths)
	{
		if (!(launch_path(lemin, i)))
			return (0);
		i++;
	}
	ft_free_int(lemin->a.rep, lemin->nbpaths);
	ft_clean(lemin->m.cases);
	return (1);
}
