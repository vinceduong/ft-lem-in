#include "lem_in.h"

void	ft_free_int(int **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		display(t_lemin *lemin)
{
	int	i;

	i = 0;
	while (lemin->r.ops[i])
	{
		ft_printf("%s \n", lemin->r.ops[i] + 2);
		free(lemin->r.ops[i]);
		i++;
	}
	free(lemin->r.ops);
	ft_free_int(lemin->m.graph, lemin->m.nbcases + 1);
	return (1);
}
