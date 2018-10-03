#include "lem_in.h"

int	display(t_lemin *lemin)
{
	int	i;

	i = 0;
	while (lemin->r.ops[i])
	{
		lemin->r.ops[i]++;
		ft_printf("%d\n", lemin->r.ops[i]);
		i++;
	}
}
