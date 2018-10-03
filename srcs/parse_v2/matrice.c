#include "../includes/lem_in.h"

int ft_check_value(int **error)
{
	int i;

	i = 0;
	while (i != 5)
	{
		if (error[i][0] == 0)
			return (0);
		i++;
	}
	return (1);
}

ft_lol(tab, lemin, error)

char *ft_strdup_matrice(char *tab)
{
	int i;
	char *str;

	i = 0;
	while (tab[i] != ' ')
		i++;
	str = (char*)malloc(sizeof(char*) * i + 1);
	str[i] = '\0';
	i = 0;
	while (str[i])
	{
		str[i] = tab[i];
		i++;
	}
	str[i] = tab[i];
	return (tab);
}

void ft_create_matrice(char **tab, t_lemin *lemin, int **error)
{
	int i;
	int n;

	i = 0;
	n = 0;
	lemin->m.cases = (char**)malloc(sizeof(char*) * error[4][0])
	lemin->m.cases[0] = ft_strdup(tab[error[0][0]]);
	lemin->m.cases[nbcases] = ft_strdup(tab[error[1][0]]);
	while (n < error[4][0])
	{
		if (tab[i + n][0] == '#')
			error[4][0]++;
		else if (n + i == error[0][0] || n + i == error[1][0])
			;
		else if (n != 0 && n != lemin->m.nbcases)
			lemin->m.cases[n + i] = ft_strdup_matrice(tab[i + n]);
		n++;
	}
	ft_patatruc(lemin, tab, error);
}
