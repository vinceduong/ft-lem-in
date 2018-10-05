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
	str = ft_strndup(tab, i);
	return (str);
}

void ft_create_matrice(char **tab, t_lemin *lemin, int **error_tab)
{
	int i;
	int n;

	i = 0;
	n = 0;
	lemin->m.cases = (char**)malloc(sizeof(char*) * lemin->m.nbcases);
	while (ft_chrstr(tab[i], ' ') == 0)
		i++;
	while (n < lemin->m.nbcases)
	{
		if (tab[i][0] == '#')
			i++;
		else
		{
			if (n == 0)
				lemin->m.cases[n] = ft_strdup_matrice(tab[error_tab[0][0]]);
			else if (n == lemin->m.nbcases)
				lemin->m.cases[n] = ft_strdup_matrice(tab[error_tab[1][0]]);
			else
			{
				if (n != error_tab[0][0] || n != error_tab[1][0])
					lemin->m.cases[n] = ft_strdup_matrice(tab[i]);
			}
			i++;
			n++;
		}
	}
	ft_patatruc(tab, lemin);
}
