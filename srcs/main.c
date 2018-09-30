#include "lem_in.h"

int	main(void)
{
	t_lemin lemin;

	ft_bzero(lemin);
	if (!parse(lemin))
	{
		printf("Parsing failed");
		printf("ERROR");
		return (0);
	}
	if (!path(lemin))
	{
		printf("Pathing failed");
		printf("ERROR");
		return (0);
	}
	if (!split_ants(lemin))
	{
		printf("Splitting failed");
		printf("ERROR");
		return (0);
	}
	if (!record(lemin))
	{
		printf("Recording failed");
		printf("ERROR");
		return (0);
	}
	if (!display(lemin))
	{
		printf("Display failed");
		printf("ERROR");
		return (0);
	}
	return (0);
}
