int	main(void)
{
	t_lemin lemin;

	ft_bzero(lemin);
	if (!parse(lemin))
	{
		printf("Parsing failed");
		printf("ERROR");
	}
	if (!path(lemin))
	{
		printf("Pathing failed");
		printf("ERROR");
	}
	if (!split_ants(lemin))
	{
		printf("Splitting failed");
		printf("ERROR");
	}
	if (!record(lemin))
	{
		printf("Recording failed");
		printf("ERROR");
	}
	if (!display(lemin))
	{
		printf("Display failed");
		printf("ERROR");
	}
	return (0);
}
