#include "lem_in.h"

void free_ops(char **ops)
{
	int i;
	
	while (ops[i])
	{
		free(ops[i]);
		i++;
	}
	free(ops);
}

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
	free_ops(lemin->r.ops);
	return (1);
}
