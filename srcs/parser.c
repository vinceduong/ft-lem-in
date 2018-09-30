#include "../includes/lem_in.h"

static char **creat_tab(char *line, char **tab)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (*line)
    {
        while (*(line + len) && *(line + len) != ' ')
            len++;
        if (!(tab[i] = (char*)malloc(len * sizeof(char) + 1)))
            return (NULL);
        while (*line && *line != ' ')
            tab[i][j++] = *(line++);
        tab[i][j] = '\0';
        j = 0;
        len = 0;
        i++;
        line++;
    }
	return (tab);
}
static char **parsetab(t_lemin lemin, char *line)
{
	char **tab;

	if (!(tab = (char**)malloc(3 * sizeof(char*))))
		return (0);
	if (line)
		return (creat_tab(line, tab));
	else
		return (NULL);
}

static int readrooms(t_lemin lemin, char *line)
{
		if (!(lemin.m.cases = parsetab(lemin, line)))
			return (0);
		printf("lemin = %s\n", *lemin.m.cases);
		return (1);
}

static int init_ants(t_ants *a)
{
	a->nbants = 0;
	a->nbstart = 0;
	a->nbend = 0;
	if (!(a->rep = (int**)malloc(sizeof(int*))))
		return (0);
	return (1);
}

static int read1(t_lemin lemin, char *line)
{
	if (!(init_ants(&lemin.a)))
		return (0);
	if (ft_isdigit(line[0]) && !ft_strchr(line, ' ') && line[0] != 'L' &&
			line[0] != '\t')
	{
		(ft_atoi(line)) ? lemin.a.nbants = ft_atoi(line) : 0;
		lemin.a.nbstart = ft_atoi(line);
		printf("nb_ants = %d\n", lemin.a.nbants);
		printf("nbstart = %d\n", lemin.a.nbstart);
	}
	else if (line[0] != '#' && ft_strchr(line, ' ') && line[0] != 'L' && \
			line[0] != '\t')
	{
		if (!(readrooms(lemin, line)))
			return(0);
	}

	return (1);
}

static	int readata(t_lemin lemin, char *line)
{
	if (!(read1(lemin, line)))
		return (0);
	return (1);
}

int	parse(t_lemin lemin)
{
	char **line;

	if (!(line = (char**)malloc(sizeof(char*))))
		return (0);
	while (get_next_line(0, line) > 0)
	{
		if (!ft_strcmp(*line, "") || !readata(lemin, *line))
			printf("Error\n");
	}
	return (1);
}
