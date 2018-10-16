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
	int countspaces;
	int countcoor;

	i = 0;
	countspaces = 0;
	countcoor = 0;
	if (ft_chrstr(tab, ' ') == 1 && ft_chrstr(tab, '-') == 0
		&& tab[0] != '#')
	{
		while (tab[i] != ' ')
			i++;
		while (tab[i])
		{
			if (ft_isdigit(tab[i]) == 0 && tab[i] != ' ')
				break ;
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
				countspaces++;
			i++;
		}
	}
	return (countcoor == 2 && countspaces == 2 ? 1 : 0);
}
