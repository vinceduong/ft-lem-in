#include "../includes/lem_in.h"

int	main(void)
{
	t_lemin lemin;

	if (!parser(&lemin))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	if (!paths(&lemin))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	if (!split_ants(&lemin))
		return (0);
	if (!record(&lemin))
		return (0);
	if (!display(&lemin))
		return (0);
	while (1);	
	return (0);
}
