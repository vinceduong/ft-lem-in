#include "lem_in.h"
# define R lemin->a.rep

/*il te manque peut etre un voup, si ca pas hesite pas a incrementer ton
 return de 1 */

void test_recu(t_lemin *lemin)
{
		int	i;
		int j;

		i = 0;
		ft_printf("\n\n\n");
		ft_printf("nbpaths is %d ", lemin->nbpaths);
		while (i < lemin->nbpaths)
		{
			j = 0;
			ft_printf("\n");
			while (R[i][j])
				{
					ft_printf("%d, ", R[i][j]);
					j++;
				}
				i++;
		}
}

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
	char *tmp;

	antpos = 1;
	while (lemin->a.rep[pathnumber][antpos] != 0)
	{
		wave = antpos - 1;
		room = lemin->p[pathnumber].nodes->start->next;
		while (room)
		{
			if (!(lemin->r.ops[wave]))
			{
				lemin->r.ops[wave] = "a";
			}
			lemin->r.ops[wave] = ft_strjoin(lemin->r.ops[wave],
				step_writer(lemin, lemin->a.rep[pathnumber][antpos], room));
			room = room->next;
			wave++;
		}
		antpos++;
	}
	return (1);
}

int	record(t_lemin *lemin)
{
	ft_printf("fds");
	test_recu(lemin);
	ft_printf("TINTIN");
	int	pathnumber;

	pathnumber = 0;
	if (!(lemin->r.ops =
				(char **)malloc(ops_size(lemin) * sizeof(char *))))
		return (0);
	while (pathnumber <= lemin->nbpaths)
	{
		launch_path(lemin, pathnumber);
		pathnumber++;
	}
	return (1);
}
