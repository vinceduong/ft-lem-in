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
	while (i != 6)
	{
		if (error_tab[i][0] <= 0)
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
	str = ft_strndup(tab, i);
	return (str);
}

void ft_create_matrice(char **tab, t_lemin *lemin, int **error_tab)
{
	int i;
	int n;

	i = 0;
	n = 0;
	lemin->m.cases = (char**)malloc(sizeof(char*) * lemin->m.nbcases + 1);
	i = error_tab[5][0];
	lemin->m.cases[0] = ft_strdup_matrice(tab[error_tab[0][0]]);
	lemin->m.cases[lemin->m.nbcases] = ft_strdup_matrice(tab[error_tab[1][0]]);
	while (i < error_tab[6][0])
	{
		if (tab[i][0] == '#')
			i++;
		else
		{
			if (n == 0 || n == lemin->m.nbcases || lemin->m.cases[n])
				;
			else
				lemin->m.cases[n] = ft_strdup_matrice(tab[i]);
			i++;
			n++;
		}
	}
	ft_patatruc(tab, lemin, error_tab);
}
