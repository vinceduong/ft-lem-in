#include "lem_in.h"

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
		while (tab[i])
		{
			if (!ft_isdigit(tab[i]) && tab[i] != ' ')
				break;
			if (ft_isdigit(tab[i]))
			{
				while (tab[i] && ft_isdigit(tab[i]))
					i++;
				countcoor++;
				if (countcoor == 2 && tab[i])
					countcoor--;
			}
			if (tab[i] == ' ')
				countspaces++;
			i++;
		}
	}
	printf("Countcoor = %d, countspaces = %d\n", countcoor, countspaces);
	return (countcoor == 2 && countspaces == 2 ? 1 : 0);
}
