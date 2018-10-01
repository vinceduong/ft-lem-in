#include "lem_in.h"

char	*step_writer(t_lemin *lemin, int antnum, int room);
{
	char *tmp;

	tmp = ft_strjoin("L", ft_itoa(antnum));
	tmp = ft_strjoin(tmp, "-");
	tmp = ft_strjoin(tmp, lemin->m->case[room]);
	return (tmp);
}

int	launch_path(t_lemin *lemin, int pathnumber)
{
	int antpos;
	int wave;
	int	room;

	antpos = 1;
	while (lemin->a->rep[pathnumber][ant])
	{
		wave = antpos - 1;
		while (wave - antpos + 1 < lemin->p[pathnumber]->length)
		{
			room = lemin->p->paths[pathnumber][wave - ant + 1];
			ops[wave] = ft_strjoin(ops[wave],
				step_writer(lemin, lemin->a->rep[pathnumber][antpos], room));
			wave++;
		}
		a++;
	}
}

int	record(t_lemin *lemin)
{
	int	pathnumber;

	pathnumber = 0;
	while (pathnumber < lemin->nbpath)
	{
		launch_path(lemin, pathnumber);
		pathnumber++;
	}
}
