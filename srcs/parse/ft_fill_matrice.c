#include "lem_in.h"

static int		**ft_fill_zero(t_lemin *lemin)
{
	int		**tab;
	int		i;
	int		n;

	tab = (int**)malloc(sizeof(int*) * lemin->m.nbcases + 1);
	i = 0;
	n = 0;
	while (n < lemin->m.nbcases + 1)
	{
		tab[n] = (int*)malloc(sizeof(int) * lemin->m.nbcases + 1);
		while (i < lemin->m.nbcases + 1)
		{
			tab[n][i] = 0;
			i++;
		}
		n++;
		i = 0;
	}
	return (tab);
}

static char		*ft_strdup_c(char *tab)
{
	int		i;
	int		n;
	char	*tmp;

	i = 0;
	n = 0;
	while (tab[n] != '-')
		n++;
	tmp = ft_strndup(tab, n);
	return (tmp);
}

static int		fill_one(t_lemin *lemin, char *str)
{
	int		i;

	i = 0;
	while (lemin->m.cases[i])
	{
		if (ft_strcmp(lemin->m.cases[i], str) == 0)
		{
			free(str);
			return (i);
		}
		i++;
	}
	free(str);
	return (-1);
}

static int		ft_minus(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '-')
		i++;
	i++;
	return (i);
}

void			ft_patatruc(char **tab, t_lemin *lemin, int *error_tab)
{
	int		n;
	int		i;
	int		index;
	int		j;

	n = 0;
	i = 0;
	j = 0;
	index = 0;
	lemin->m.graph = ft_fill_zero(lemin);
	index = error_tab[6];
	while (tab[index])
	{
		if (tab[index][0] == '#')
			index++;
		else
		{
			n = fill_one(lemin, ft_strdup_c(tab[index]));
			i = fill_one(lemin, ft_strdup(tab[index] + ft_minus(tab[index])));
			lemin->m.graph[n][i] = 1;
			lemin->m.graph[i][n] = 1;
			index++;
			j++;
		}
	}
}
