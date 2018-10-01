#include "lem_in.h"

char	*step_writer(t_lemin *lemin, int ant, int room);
{
	char *tmp;

	tmp = ft_strjoin("L", ft_itoa(ant));
	tmp = ft_strjoin(tmp, "-");
	tmp = ft_strjoin(tmp, lemin->m->case[room]);
	return (tmp);
}

int	launch_path(t_lemin *lemin, int pathnumber)
{
	int ant;
	int wave;
	int	room;

	ant = 1;
	wave = 0;
	while (lemin->a->rep[pathnumber][ant])
	{
		while (wave - ant + 1 < lemin->p->paths[pathnumber]->length)
		{
			room = lemin->p->paths[pathnumber][wave - ant + 1];
			ops[wave] = ft_strjoin(ops[wave], step_writer(lemin, ant, room));
			wave++;
		}
		a++;
	}
}

int	record(t_lemin *lemin)
{
	int	pathnumber;

	pathnumber = 0;
	while (pathnumber < lemin->p->nbpath)
	{
		launch_path(lemin, pathnumber);
		pathnumber++;
	}
}





	{
		lemin->r->ops[wave] = tmp;
	}



}
