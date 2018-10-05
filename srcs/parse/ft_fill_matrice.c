#include "lem_in.h"

static int **ft_fill_zero(t_lemin *lemin)
{
	int **tab;
	int i;
	int n;

	tab = (int**)malloc(sizeof(int*) * lemin->m.nbcases + 1);
	i = 0;
	n = 0;
	while (n < lemin->m.nbcases + 1)
	{
		tab[n] = (int*)malloc(sizeof(int) * lemin->m.nbcases + 1);
		while (i < lemin->m.nbcases + 1)
		{
			tab[n][i] = 0;
			//printf("%d", tab[n][i]);
			i++;
		}
		//printf(" = %d\n", n);
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

void ft_patatruc(char **tab, t_lemin *lemin, int **error_tab)
{
	int n;
	int i;
	int index;
	char *str;
	int j;

	n = 0;
	i = 0;
	j = 0;
	index = 0;
	lemin->m.graph = ft_fill_zero(lemin);
	index = error_tab[6][0];
	while (j < lemin->nb_link)
	{
		printf("%s\n", lemin->m.cases[1]);
		if (tab[index][0] == '#')
			index++;
		else
		{
			str = ft_strdup_c(tab[index]);
			n = find_wich_char(lemin, str);
			str = ft_strdup(tab[index] + ft_find_minus(tab[index]));
			i = find_wich_char(lemin, str);
			printf("N = %d I = %d\n", n, i);
			lemin->m.graph[n][i] = 1;
			lemin->m.graph[i][n] = 1;
			free(str);
			index++;
			j++;
		}
	}
}
