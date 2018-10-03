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
