#include "lem_in.h"
# define R lemin->a.rep

size_t		ops_size(t_lemin *lemin)
{
	size_t i;

	i = 0;
	while (lemin->a.rep[0][i])
		i++;
	return (i + (size_t)lemin->p[0].nodes->length + 1);
}

char		*step_writer(t_lemin *lemin, int antnum, t_node *room)
{
	char *tmp;
	char *itoa;

	itoa = ft_itoa(antnum);
	tmp = ft_strjoin(" L", itoa);
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
			if (!(lemin->r.ops[wave]))
				lemin->r.ops[wave] = ft_strdup("i");
			step = step_writer(lemin, lemin->a.rep[pathnumber][antpos], room);
			lemin->r.ops[wave] = ft_strjoinfree(lemin->r.ops[wave],
				step);
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
	int	pathnumber;

	pathnumber = 0;
	if (!(lemin->r.ops =
				(char **)malloc(ops_size(lemin) * sizeof(char *))))
		return (0);
	while (pathnumber < lemin->nbpaths)
	{
		launch_path(lemin, pathnumber);
		pathnumber++;
	}
	ft_free_int(lemin->a.rep, lemin->nbpaths);
	ft_clean(lemin->m.cases);
	return (1);
}
