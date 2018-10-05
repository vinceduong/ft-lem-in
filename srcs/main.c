#include "../includes/lem_in.h"

int	main(void)
{
	t_lemin lemin;
/*	int i;
	i = 0;
	lemin.m.graph = (int **)malloc(sizeof (int *) * 4);
	while (i < 4)
	{
	lemin.m.graph[i] = (int *)malloc(sizeof (int) * 4);
		i++;
	}
lemin.m.graph[0][0] = 0; lemin.m.graph[0][1] = 1;lemin.m.graph[0][2] =1;lemin.m.graph[0][3] =0;
lemin.m.graph[1][0]=1;lemin.m.graph[1][1]=0;lemin.m.graph[1][2]=0;lemin.m.graph[1][3] =1;
lemin.m.graph[2][0]=1;lemin.m.graph[2][1]=0;lemin.m.graph[2][2]=0;lemin.m.graph[2][3] =1;
lemin.m.graph[3][0]=0;lemin.m.graph[3][1]=1;lemin.m.graph[3][2]=1;lemin.m.graph[3][3] =0;
	lemin.m.nbcases = 4;
	*/if (!parser(&lemin))
	{
		ft_printf("Parsing failed");
		ft_printf("ERROR");
		return (0);
	}
	if (!paths(&lemin))
	{
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
	print_matrix(&lemin);
	/*
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
