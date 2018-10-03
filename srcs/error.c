#include "lem_in.h"

int	ft_error(char *reason)
{
	int i;

	i = 0;
	while (ft_strcmp(reason, tab_errors[i].reason) != 0)
		i++;
	ft_putendl(tab_errors[i].str_print);
	return (tab_errors[i].type_error);
}
