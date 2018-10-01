#include "../includes/lem_in.h"

int	save_instrus(char *line, t_lemin *lemin)
{
	t_list		*new;

	new = NULL;
	if (!(lemin->instru))
	{
		if (!(lemin->instru = ft_lstnew(line, ft_strlen(line) + 1)))
			return (0);
	}
	else
	{
		if (!(new = ft_lstnew(line, ft_strlen(line) + 1)))
			return (0);
		ft_lstaddend(&(lemin->instru), new);
	}
	return (1);
}

static int init_ants(t_ants *a)
{
	if (!(a = (t_ants*)malloc(sizeof(t_ants))))
		return (0);
	a->nbants = 0;
	a->nbstart = 0;
	a->nbend = 0;
	return (1);
}

static int read1(t_lemin *lemin, char *line)
{

	if (!(init_ants(&lemin->a)))
		return (0);
	if (ft_isdigit(line[0]) && !ft_strchr(line, ' ') && line[0] != 'L' &&
			line[0] != '\t')
	{
		(ft_atoi(line)) ? lemin->a.nbants = ft_atoi(line) : 0;
		lemin->a.nbstart = ft_atoi(line);
		lemin->a.nbend = 0;
	}
	else if (line[0] != '#' && ft_strchr(line, ' ') && line[0] != 'L' && \
			line[0] != '\t')
	{
		if (!(readrooms(lemin, line)))
			return(0);
	}
	return (1);
}

static	int readata(t_lemin *lemin, char *line)
{
	if (!(read1(lemin, line)))
		return (0);
	if (!(save_instrus(line, lemin)))
		return (0);
	return (1);
}

int check_error(t_lemin *lemin)
{
	
	printf("nb_start = %d\n", lemin->a.nbstart);
	printf("nb_end = %d\n", lemin->a.nbend);
	printf("lemin = %s\n", *lemin->m.cases);
	printf("ants = %d\n", lemin->a.nbants);
	return (1);
}

int	parse(t_lemin *lemin)
{
	char **line;

	if (!(lemin = init_lem(lemin)))
    return (0);
	if (!(line = (char**)malloc(sizeof(char*))))
		return (0);
	while (get_next_line(0, line) > 0)
	{
		if (!ft_strcmp(*line, "") || !readata(lemin, *line))
			return (0);
		free(*line);
	}
	if(!(check_error(lemin)))
		return (0);
	/*free(line);
	free(lemin);
	printf("nb_start = %d\n", lemin->a.nbstart);
	printf("nb_end = %d\n", lemin->a.nbend);
	printf("lemin = %s\n", *lemin->m.cases);
	printf("ants = %d\n", lemin->a.nbants);
	print_instru(lemin);*/
	return (1);
}
