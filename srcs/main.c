#include "../includes/lem_in.h"

int	main(void)
{
	t_lemin lemin;

	if (!parser(&lemin))
	{
		ft_printf("Parsing failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!paths(&lemin))
	{
		print_matrix(&lemin);
		ft_printf("Pathing failed\n");
		ft_printf("ERROR\n");
		return (0);
	}
	int i = 0;
	printf("-----THE FINALS PATHS-----\n");
	while (i < lemin.nbpaths)
	{
		print_path(&lemin.p[i]);
		i++;
	}
	if (!split_ants(&lemin))
	{
		ft_printf("Splitting failed");
		ft_printf("ERROR");
		return (0);
	}
	printf("Split ants worked\n");
	if (!record(&lemin))
	{
		ft_printf("Recording failed");
		ft_printf("ERROR");
		return (0);
	}
	printf("Record worked\n");
	if (!display(&lemin))
	{
		ft_printf("Display failed");
		ft_printf("ERROR");
		return (0);
	}
	printf("Display worked\n");
	return (0);
}
