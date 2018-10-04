#include "../includes/lem_in.h"

int	main(void)
{
	t_lemin lemin;

	ft_bzero(&lemin, sizeof(t_lemin));
	if (!parser(&lemin))
	{
		ft_printf("Parsing failed");
		ft_printf("ERROR");
		return (0);
	}/*
	if (!paths(&lemin))
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
		ft_printf("Display failed");
		ft_printf("ERROR");
		return (0);
	}*/
	return (0);
}
