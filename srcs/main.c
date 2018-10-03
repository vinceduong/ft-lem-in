#include "../includes/lem_in.h"

int	main(void)
{
	t_lemin lemin;

	if (!parse(&lemin))
	{
		printf("Parsing failed\n");
		printf("ERROR");
	}
	/*if (!path(lemin))
	{
		ft_printf("Pathing failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!split_ants(&lemin))
	{
		ft_printf("Splitting failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!record(&lemin))
	{
		ft_printf("Recording failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!display(&lemin))
	{
		printf("Display failed");
		printf("ERROR");
	}*/
	return (0);
}
