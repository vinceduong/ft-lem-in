#include "../lem_in.h"

int **ft_fill_zero(t_lemin *lemin)
{
	int **tab;
	int i;
	int n;
	int j;

	tab = (int**)malloc(sizeof(int*) * lemin->m.nbcases);
	i = 0;
	n = 0;
	j = 0;
	while (j < lemin->m.nbcases)
	{
		tab[n] = (int*)malloc(sizeof(int) * lemin->m.nbcases);
		while (i < lemin->m.nbcases)
		{
			tab[n][i] = 0;
			i++;
		}
		n++;
		i = 0;
		j++;
	}
	return (tab);
}

char *ft_strdup_c(char *tab)
{
	int i;
	int n;
	char *tmp;

	i = 0;
	n = 0;
	while (tab[n] != '-' || tab[n])
		n++;
	tmp = (char*)malloc(sizeof(char*) * n + 1);
	while (i < n)
	{
		tmp[i] = tab[i];
		i++;
	}
	tmp[i] = tab[i];
	return (tmp);

}

int find_wich_char(t_lemin *lemin, char *str)
{
	int i;

	i = 0;
	while (lemin->m.cases[i] != str)
		i++;
	return (i);
}

int ft_find_minus(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '-')
		i++;
	return (i);
}

void ft_patatruc(char **tab, t_lemin *lemin, int **error)
{
	int n;
	int i;
	int index;
	int index2;
	char *str;

	n = 0;
	i = 0;
	index = 0;
	lemin->m.graph = ft_fill_zero(lemin);
	while (ft_chrstr(tab[index2], '-') == 0)
		index2++;
	while (index < lemin->m.nbcases)
	{
		str = ft_strdup_c(tab[index2 + index]);
		n = find_wich_char(lemin, str);
		str = ft_strdup(tab[index + index2][ft_find_minus(tab)]);
		i = find_wich_char(lemin, str);
		lemin->m.graph[n][i] = 1;
		lemin->m.graph[i][n] = 1;
		free(str);
		index++;
	}
}
