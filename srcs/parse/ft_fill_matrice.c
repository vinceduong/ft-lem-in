#include "lem_in.h"

static int **ft_fill_zero(t_lemin *lemin)
{
	int **tab;
	int i;
	int n;

	tab = (int**)malloc(sizeof(int*) * lemin->m.nbcases + 1);
	i = 0;
	n = 0;
	while (n < lemin->m.nbcases)
	{
		tab[n] = (int*)malloc(sizeof(int) * lemin->m.nbcases + 1);
		while (i < lemin->m.nbcases)
		{
			tab[n][i] = 0;
			i++;
		}
		n++;
		i = 0;
	}
	return (tab);
}

static char *ft_strdup_c(char *tab)
{
	int i;
	int n;
	char *tmp;

	i = 0;
	n = 0;
	while (tab[n] != '-')
		n++;
	tmp = ft_strndup(tab, n);
	return (tmp);

}

static int find_wich_char(t_lemin *lemin, char *str)
{
	int i;

	i = 0;
	while (lemin->m.cases[i])
	{
		if (ft_strcmp(lemin->m.cases[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int ft_find_minus(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '-')
		i++;
	i++;
	return (i);
}

void ft_patatruc(char **tab, t_lemin *lemin)
{
	int n;
	int i;
	int index;
	int index2;
	char *str;

	n = 0;
	i = 0;
	index = 0;
	index2 = 0;
	lemin->m.graph = ft_fill_zero(lemin);
	while (ft_chrstr(tab[index2], '-') == 0)
		index2++;
	while (index < lemin->nb_link)
	{
		str = ft_strdup_c(tab[index2 + index]);
		n = find_wich_char(lemin, str);
		str = ft_strdup(tab[index + index2] + ft_find_minus(tab[index + index2]));
		i = find_wich_char(lemin, str);
		lemin->m.graph[n][i] = 1;
		lemin->m.graph[i][n] = 1;
		print_matrix(lemin);
		free(str);
		index++;
	}
}
