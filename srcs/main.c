#include "../includes/lem_in.h"

int	main(void)
{
	t_lemin lemin;

	if (!parser(&lemin))
	{
		ft_printf("Parsing failed\n");
		ft_printf("ERROR\n");
		return (0);
	}
	printf("Parsing worked\n");
	if (!paths(&lemin))
	{
		ft_printf("Pathing failed\n");
		ft_printf("ERROR\n");
		return (0);
	}
	printf("Pathing worked\n");
	if (!split_ants(&lemin))
	{
		ft_printf("Splitting failed\n");
		ft_printf("ERROR\n");
		return (0);
	}
	printf("Split ants worked\n");
	if (!record(&lemin))
	{
		ft_printf("Recording failed\n");
		ft_printf("ERROR\n");
		return (0);
	}
	printf("Record worked\n");
	if (!display(&lemin))
	{
		ft_printf("Display failed\n");
		ft_printf("ERROR\n");
		return (0);
	}
	printf("Display worked\n");
	return (0);
}
