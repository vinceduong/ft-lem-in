#include "../../includes/lem_in.h"

int			save_instrus(char *instru, t_lemin *lemin)
{
	t_list		*new;

	new = NULL;
	if (!(lemin->instru))
	{
		if (!(lemin->instru = ft_lstnew(instru, ft_strlen(instru) + 1)))
			return (0);
	}
	else
	{
		if (!(new = ft_lstnew(instru, ft_strlen(instru) + 1)))
			return (0);
		ft_lstadd(&(lemin->instru), new);
	}
	return (1);
}

static int parse_instru(t_lemin *lemin, char *line)
{
		if (line[0] != '#' && ft_isdigit(line[0]) && !ft_strchr(line, ' ') \
				&& !ft_strchr(line, '-') && ft_is_int(line) && line[0] != '\t')
		{
			(ft_atoi(line) > 0) ? lemin->a.nbants = ft_atoi(line) : 0;
			lemin->a.nbstart = ft_atoi(line);
		}
		else if (!ft_strchr(line, '-') && line[0] != '#' && ft_strchr(line, ' ') \
				&& line[0] != ' ' && line[0] != '\t')
		{
			//lemin->nb_rooms++;
			//if (!(readrooms(lemin, line)))
			//	return (0);
		//	if(!(create_rooms(lemin, line)))
		//		return (0);
		}
		else if (ft_strchr(line, '-') && line[0] != '#' && line[0] != '\t' \
				&& line[0] != '#' && !ft_strchr(line, ' ') && line[0] != ' ')
		{
			lemin->nb_link++;
		}
	return (1);
}

/* readdata est accompli pour chaque ligne successive*/

static int readdata(t_lemin *lemin, char *line)
{
	if (line[0] == 'L')
		return (0);
	if (!(save_instrus(line, lemin)))
		return (0);
	if (!(parse_instru(lemin, line)))
		return (0);
	if (!(read_start_end(lemin, line)))
		return (0);
	return (1);
}

static int check_error(t_lemin *lemin)
{

	if (lemin->a.nbants <= 0 || lemin->start != 1 || lemin->end != 1 ||
			lemin->nb_link == 0)
		return (0);
	printf("ants = %d\n", lemin->a.nbants);
	//printf("lemin = %s\n", lemin->m.cases[0]);
	printf("nb_start = %d\n", lemin->a.nbstart);
	printf("nb_end = %d\n", lemin->a.nbend);
	printf("start = %d\n", lemin->start);
	printf("end = %d\n", lemin->end);
	printf("nb_link = %d\n", lemin->nb_link);
	printf("nb_rooms = %d\n", lemin->nb_rooms);
	//printf("matrice = %d\n", lemin->m.graph[0][0]);
	return (1);
}

int	parse(t_lemin *lemin)
{
	char **line;

	lemin = NULL;
	if (!(lemin = init_lem(lemin)))
    return (0);
	init_ants(&lemin->a);
	while (get_next_line(0, line) >= 0)
	{
		if (!ft_strcmp(*line, "") || !readdata(lemin, *line))
			return (0);
		free(*line);
	}
	tab = malloc


	//print_instru(lemin);
	if(!(check_error(lemin)))
		return (0);
	//init_graph(lemin);
	//print_matrix(&lemin->m, lemin);
	return (1);
}
