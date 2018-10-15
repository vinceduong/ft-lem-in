#include "lem_in.h"

void	ft_clean(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(&tab[i]);
	ft_strdel(tab);
	free(tab);
}

int		ft_intlen(int nb)
{
	int i;

	i = 1;
	if (nb >= 0 && nb <= 9)
		return (i + 1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int		ft_coord_is_digit(char *tab)
{
	int i;

	int countspaces = 0;
	int countcoor = 0;
	i = 0;
	if (ft_chrstr(tab, ' ') == 1 && ft_chrstr(tab, '-') == 0
		&& tab[0] != '#')
	{
		while (tab[i] != ' ')
			i++;
		while (tab[i] != '\n')
		{
			if (ft_isdigit(tab[i]) == 0 && tab[i] != ' ')
				break;
			if (ft_isdigit(tab[i]) == 1)
			{
				while (tab[i] && ft_isdigit(tab[i]) == 1)
					i++;
				countcoor++;
				if (countcoor >= 2 && tab[i])
					countcoor--;
				if (!tab)
					break ;
			}
			if (tab[i] == ' ')
			{
				printf("%s %d\n", tab + i, i);
				countspaces++;
			}
			i++;
		}
	}
	printf("[%s]\nCountcoor = %d, countspaces = %d\n", tab, countcoor, countspaces);
	return (countcoor == 2 && countspaces == 2 ? 1 : 0);
}
