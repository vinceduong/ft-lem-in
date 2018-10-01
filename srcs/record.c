#include "lem_in.h"

char	*step_writer(int ant, char *room);
{
	char *tmp;

	tmp = ft_strjoin("L", ft_itoa(ant));
	tmp = ft_strjoin(tmp, "-");
	tmp = ft_strjoin(tmp, room);
	return (tmp);
}

int	launch_path(t_lemin *lemin, int pathnumber)
{
	int wave;
	int i;

	while (i < wave)
	{
		
	}
}
int	record(t_lemin *lemin)
{
	int		i;

	i = 0;
	while (i < lemin->nbpaths)
	{
		launch_path(lemin, i);
		i++;
	}
}





	{
		tmp = ft_strjoin(tmp, step_writer(ant, room));
		lemin->r->ops[wave] = tmp;
	}



}
