#include "lem_in.h"

int		ft_intlen(int nb)
{
	int i;

	i = 1;
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

	i = 0;
	while (tab[i])
	{
		if (tab[i] == ' ')
			break;
		i++;
	}
	/*i++;
	if (ft_isdigit(tab[i]) == 1)
	{
		i += ft_intlen(ft_atoi(tab + i));
		if (ft_isdigit(tab[i]) == 1)
		{
			i++;
			printf("%s\n", tab + i);
			if (tab[i] == '\0')
				return (1);
			}
	}*/
	return (1);
}
