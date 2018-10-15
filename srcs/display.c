#include "lem_in.h"

int	display(t_lemin *lemin)
{
	int	i;

	i = 0;
	while (lemin->r.ops[i])
	{
		lemin->r.ops[i] += 2;
		ft_printf("%s \n", lemin->r.ops[i]);
		i++;
	}
	//free(lemin->r.ops);
	return (1);
}
