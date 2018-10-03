#include "lem_in.h"

/*il te manque peut etre un voup, si ca pas hesite pas a incrementer ton
 return de 1 */

size_t		ops_size(t_lemin *lemin)
{
	size_t i;

	i = 0;
	while (lemin->a.rep[0][i])
		i++;
	return (i + (size_t)lemin->p[0].nodes->length);
}

char	*step_writer(t_lemin *lemin, int antnum, t_node *room)
{
	char *tmp;

	tmp = ft_strjoin(" L", ft_itoa(antnum));
	tmp = ft_strjoin(tmp, "-");
	tmp = ft_strjoin(tmp, lemin->m.cases[room->nb]);
	return (tmp);
}

int	launch_path(t_lemin *lemin, int pathnumber)
{
	int antpos;
	int wave;
	t_node *room;

	antpos = 1;
	while (lemin->a.rep[pathnumber][antpos] != 0)
	{
		wave = antpos - 1;
		room = lemin->p[pathnumber].nodes->start->next;
		while (room)
		{
			lemin->r.ops[wave] = ft_strjoin(lemin->r.ops[wave],
				step_writer(lemin, lemin->a.rep[pathnumber][antpos], room));
			room = room->next;
			wave++;
		}
		lemin->r.ops[wave] = NULL;
		antpos++;
	}
	return (1);
}

int	record(t_lemin *lemin)
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
	return (1);
}
