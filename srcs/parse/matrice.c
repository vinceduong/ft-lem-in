#include "lem_in.h"

int		ft_chrstr(char *find, int c)
{
	int i;

	i = -1;
	while (find[++i])
	{
		if (find[i] == c)
			return (1);
	}
	return (find[i] == c ? 1 : 0);
}

int ft_check_value(int **error_tab)
{
	int i;

	i = 0;
	while (i != 4)
	{
		if (error_tab[i][0] == 0)
			return (0);
		i++;
	}
	return (1);
}

static char *ft_strdup_matrice(char *tab)
{
	int i;
	char *str;

	i = 0;
	while (tab[i] != ' ')
		i++;
	str = (char*)malloc(sizeof(char*) * i + 1);
	str[i + 1] = '\0';
	i = 0;
	while (str[i])
	{
		str[i] = tab[i];
		i++;
	}
	//str[i] = tab[i];
	return (tab);
}

void ft_create_matrice(char **tab, t_lemin *lemin, int **error_tab)
{
	int i;
	int n;

	i = 0;
	n = 0;
	lemin->m.cases = (char**)malloc(sizeof(char*) * error_tab[4][0] + 1);
	lemin->m.cases[error_tab[4][0] + 1] = 0;
	lemin->m.cases[0] = ft_strdup(tab[error_tab[0][0]]);
	lemin->m.cases[lemin->m.nbcases] = ft_strdup(tab[error_tab[1][0]]);
	while (ft_chrstr(tab[i], '-') != 1)
		i++;
	while (lemin->m.cases[n] != 0)
	{
		if (tab[i][0] == '#')
			i++;
		else
		{
			lemin->m.cases[n] = ft_strdup_matrice(tab[i]);
			i++;
			n++;
		}
	}
	printf("%s\n", "yo");
	ft_patatruc(tab, lemin);
}
