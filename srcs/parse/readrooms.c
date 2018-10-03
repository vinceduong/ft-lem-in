#include "../../includes/lem_in.h"

int 	checkrooms(char **tab, char *line, t_lemin *lemin)
{
	int n;
	int i;
	int j;

	i = 0;
	j = 0;
	n = 0;
	while (*line)
	{
		while (*(line + n) && *(line + n) != ' ')
			n++;
		if (!(tab[i] = (char*)malloc(n * sizeof(char) + 1)))
			return (0);
		while (*line && *line != ' ')
			tab[i][j++] = *(line++);
		tab[i][j] = '\0';
		n = 0;
		j = 0;
		i++;
		line++;
	}
	if (!ft_isdigit(tab[1][0]) || !ft_isdigit(tab[2][0]) || !ft_is_int(tab[1]) \
			|| !ft_is_int(tab[2]))
		return (0);
	return (1);
}

void		print_matrix(t_map *m, t_lemin *lemin)
{
	int i;
	int j;

	i = -1;
	while (++i < lemin->nb_rooms)
	{
		j = -1;
		while (++j < lemin->nb_rooms)
		{
			printf("%d\n", m->graph[i][j]);
			ft_putchar(' ');
		}
	}
}

int init_graph(t_lemin *lemin)
{
	int i;
	int j;

	t_map *m;
	i = -1;
	m->graph = (int **)malloc(sizeof(int *) * lemin->nb_rooms);
	while (++i < lemin->nb_rooms)
	{
		if(!(m->graph[i] = (int*)malloc(sizeof(int) * lemin->nb_rooms)))
			return (0);
		j = 0;
		while (m->graph[i][j])
		{
			m->graph[i][j] = 0;
			j++;
		}
	}
	return(1);
}

int create_rooms(t_lemin *lemin, char *line)
{
	int i;
	int j;
	char *tmp;

	i = -1;
	tmp = line;
	tmp = *ft_strsplit(line, ' ');
	if (!(lemin->m.cases = (char**)malloc(sizeof(char*))))
		return (0);
	while (++i < lemin->nb_rooms)
	{
		if (!(lemin->m.cases[i] = (char*)malloc(ft_strlen(line) * sizeof(char) + 1)))
			return (0);

		while (lemin->m.cases[i][j])
		{
				lemin->m.cases[i][j] = *tmp;
				j++;
		}
		line++;
	}
	return (1);
}

int readrooms(t_lemin *lemin, char *line)
{
	char **tab;

//	lemin->nb_rooms++;
	tab = NULL;
	if (!(tab = (char**)malloc(sizeof(char*))))
		return (0);
	if (!(checkrooms(tab, line, lemin)))
		return (0);
	return (1);
}
