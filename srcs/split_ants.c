#include "../includes/lem_in.h"

int ft_clean(int **lpath, int i)
{
	while (i)
		free(lpath[i--]);
	free(lpath);
	exit(0);
}

int ft_check_lost(int **lpath, int ant)
{
	int value;
	int i;

	value = 0;
	i = 0;
	while (lpath[i][0] != 0 || lpath[i][1] != 0)
	{
		value += lpath[i][1];
		i++;
	}
	return (value == ant ? 0 : ant - value);
}

int **ft_assign_ant(int **lpath, t_lemin *lemin, int i, int ant)
{
	int value;
	int i2;

	value = 0;
	i2 = 0;
	while (ant)
	{
		if (i == lemin->nbpaths)
			value = ant / lemin->nbpaths;
		else
			value = lpath[i + 1][0] - lpath[i][0];
		i2 = i;
		if (ant - (value * i) < 0)
		{
			while (ant - (value * i) < 0)
			{
				i--;
				i2--;
			}
		}
		else
			ant = ant - (value * i);
		while (i2-- > 0)
			lpath[i2][1] += value;
		i++;
	}
	ft_check_lost(lpath, lemin->a.nbants);
	return (lpath);
}

void ft_put_ant_in_tube(int **lpath, t_lemin *lemin, int i)
{
	int n;
	int ant;
	int er;

	n = 0;
	ant = 0;
	er = 0;
	while (i < lemin->nbpaths)
	{
		if (!(lemin->a.rep[i] = (int*)malloc(sizeof(int)
		* (lpath[i][1] == 0 ? 1 : lpath[i][1] + 1))))
		{
			ft_clean(&lemin->a.rep[i], i);
			exit(0);
		}
		lpath[i][1] != 0 ? lemin->a.rep[i][lpath[i][1] + 1] = 0 :
		(lemin->a.rep[i][0] = 0);
		i++;
	}
	i = 0;
	while (ant < lemin->a.nbants)
	{
		if (lemin->a.rep[n][i] == 0)
		{
			n = 0;
			i++;
		}
		lemin->a.rep[n++][i] = ant++;
	}
}

int **ft_length_of_each_path(int **lpath, t_lemin *lemin)
{
	int i;

	i = 0;
	if (!(lpath = (int**)malloc(sizeof(int*) * lemin->nbpaths + 1)))
		return (0);
	if (!(lemin->a.rep = (int**)malloc(sizeof(int*) * lemin->nbpaths + 1)))
		return (0);
	while (i < lemin->nbpaths)
	{
		if (!(lpath[i] = (int*)malloc(sizeof(int) * 2)))
		{
			ft_clean(lpath, i);
			lpath = 0;
			return (lpath);
		}
		lpath[i][1] = 0;
		lpath[i++][0] = lemin->p[0].nodes->length;
	}
	lpath[i] = 0;
	lemin->a.rep[i] = 0;
	return (lpath);
}

int split_ants(t_lemin *lemin)
{
	int **lpath;

	lpath = 0;
	lpath = ft_length_of_each_path(lpath, lemin);
	if (lpath == 0)
		return (0);
	lpath = ft_assign_ant(lpath, lemin, 0, lemin->a.nbants);
	if (lpath == 0)
		return (0);
	ft_put_ant_in_tube(lpath, lemin, 0);
	return (1);
}

/*98 - 95 - 79 - 40
 x / n = xf
98
4 = 3 + 8 + 13 + 10 == 	34
7 = 8 + 13 + 10 == 		31
15 = 13 + 10 == 		23
38 = 10 = 				10
*/
