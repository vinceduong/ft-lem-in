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

static void init_ants(t_ants *a)
{
	a->nbants = 0;
	a->nbstart = 0;
	a->nbend = 0;
}

static int read1(t_lemin *lemin, char *line)
{
	char **tab;

	tab = NULL;
	if (!(tab = (char**)malloc(sizeof(char*))))
		return (0);
		if (line[0] != '#' && line[0] != 'L' && ft_isdigit(line[0]) && \
				!ft_strchr(line, ' ') && !ft_strchr(line, '-') && ft_is_int(line))
		{
			(ft_atoi(line) > 0) ? lemin->a.nbants = ft_atoi(line) : 0;
			lemin->a.nbstart = ft_atoi(line);
		}
		else if (!ft_strchr(line, '-') && line[0] != '#' && line[0] != 'L' && \
        ft_strchr(line, ' ') && line[0] != ' ' && line[0] != '\t')
		{
			if (!(readrooms(lemin, line)))
				return (0);
			if (!(checkrooms(tab, line)))
				return (0);
		}
		else if (ft_strchr(line, '-') && line[0] != '#' && line[0] != '\t' \
				&& line[0] != '#' && !ft_strchr(line, ' ') && line[0] != ' ')
		{
			return (1);
			//printf("tubes\n");
		}
	return (1);
}

int readdata(t_lemin *lemin, char *line)
{
	if (line[0] == 'L')
		return (0);
	if (!(read1(lemin, line)))
		return (0);
	if (!(save_instrus(line, lemin)))
		return (0);
	if (!(readdata2(lemin, line)))
		return (0);
	return (1);
}

static int check_error(t_lemin *lemin)
{

	if (lemin->a.nbants <= 0 || !lemin->instru || !lemin->start || !lemin->end \
				|| !lemin->m.cases)
		return (0);
	printf("ants = %d\n", lemin->a.nbants);
	printf("lemin = %s\n", *lemin->m.cases);
	printf("nb_start = %d\n", lemin->a.nbstart);
	printf("nb_end = %d\n", lemin->a.nbend);
	printf("start = %s\n", lemin->start);
	printf("end = %s\n", lemin->end);
	return (1);
}

int	parse(t_lemin *lemin)
{
	char **line;

	lemin = NULL;
	if (!(lemin = init_lem(lemin)))
    return (0);
	init_ants(&lemin->a);
	if (!(line = (char**)malloc(sizeof(char*))))
		return (0);
	while (get_next_line(0, line) > 0)
	{
		if (!ft_strcmp(*line, "") || !readdata(lemin, *line))
			return (0);
		free(*line);
	}
	print_instru(lemin);
	if(!(check_error(lemin)))
		return (0);
	free(lemin->start);
	free(lemin->end);
	free(lemin);
	free(line);
	return (1);
}
