#include "lem_in.h"

int **ft_assign_ant(int **lpath, t_lemin *lemin, int i, int ant)
{
	int value;

	value = 0;
	while (ant)
	{
		if (i == lemin->nbpaths)
		{
			value = ant / lemin->nbpaths;
			ft_add_value(lemin, value, lpath, i);
		}

	}
}

int **ft_length_of_each_path(int **lpath, t_lemin *lemin)
{
	int i;
	int ant;

	i = 0;
	ant = lemin.a->nbants;
	lpath = (int**)malloc(sizeof(int*) * lemin->nbpaths + 1);
	lemin.a->rep = (int**)malloc(sizeof(int*) * lemin->nbpaths + 1);
	while (lemin.p[0].start->next != NULL)
	{
		lpath = (int*)malloc(sizeof(int) * 1);
		lpath[1] = 0;
		lpath[i][0] = lemin.p[0].start.node->length;
		i++;
	}
	lpath[i] = 0;
	lemin.a->rep[i] = 0;
	return (ft_assign_ant(lapth, lemin, 0, ant));
}

int split_ants(t_lemin *lemin)
{
	int **lpath;

	lpath = 0;
	lpath = ft_length_of_each_path(lpath, lemin);
}

//lemin.p[0].start.node->length


/*98 - 95 - 79 - 40

7 - 4 = 3;
15 - 7 = 8;
38 - 15 = 13;
 x / n = xf;


while (fourmi)
{
	if (n == nbpaths)
		reste = fourmi / chemin;
	else if (reste > 0)
	{
		while (reste)
		{
			n = 0;
			n == nbpaths ? n == 0 : 0;

		}
	}
	ft_addition_path();
}
}


4 = 3 + 8 + 13 + 10 == 	34
7 = 8 + 13 + 10 == 		31
15 = 13 + 10 == 		23
38 = 10 = 				10
*/
