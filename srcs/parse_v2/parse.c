#include "../includes/lem_in.h"

/*
start = [0];
end = [1];
ant = [2];
tube = [3];
room = [4];
*/

void ft_clear_1(char **tab, int i)
{
	while (i)
		free(tab[i--]);
	free(tab);
}

static void ft_read_start_and_end(t_lemin *lemmin, char **tab, int i)
{
	if (tab[i] == "##start" && tab[i] == "##end" && tab[i + 1][0] != '#' &&
	ft_chrstr(tab[i + 1], ' ') == 0 && ft_chrstr(tab[i + 1], '-') == 0)
		tab[i] == "##start" ? error[0][0] = i + 1 : (error[1][0] = i + 1)
}

static void ft_read_data(char **tab, t_lemin *lemin, int i, int **error)
{
	while (tab[++i] != NULL)
	{
		if (tab[i] == "##start" || tab[i] == "##end")
			ft_read_start_and_end(lemin, tab, i, error);
		else if (ft_isdigit(tab[i][0]) == 1 && lemin->a.nbants == 0 &&
		ft_chrstr(tab[i], ' ') == 0 && ft_chrstr(tab[i], '-') == 0)
			error[2][0]++;
		else if (ft_chrstr(tab[i], '-') == 1 && ft_chrstr(tab[i], ' ') == 0)
			error[3][0]++;
		else if (ft_chrstr(tab[i], ' ') == 1 && ft_chrstr(tab[i], '-') == 0)
			error[4][0]++;
		else if (tab[i][0] == '#')
			;
		else
			ft_error();
	}
	ft_check_value(error) == 0 ? exit(0) : 0;
	ft_create_matrice(tab, lemin, error);
}

char **ft_read(char *str, char *line, cahr **tab)
{
	while (get_next_line(0, &line) > 0)
	{
		str = ft_strjoin(str, line);
		str[ft_strlen(str)] = '\n';
		ft_strdel(&line);
	}
	return (ft_strsplit(str, '\n'));
}

int **ft_create_error_tab()
{
	int i;
	int **tab;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * 6)))
		exit(0);
	while (i != 6)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * 1)))
		{
			ft_clear_1(tab, i);
			exit (1);
		}
		tab[i][0] = 0;
		tab[i][1] = 0;
		i++;
	}
	return (i);
}

int parser(t_lemin *lemin)
{
	char **tab;
	char *str;
	char *line;
	int **error;

	tab = NULL;
	str = ft_memalloc(0);
	line = NULL;
	error = ft_create_error_tab();
	tab = ft_read(str, line, tab);
	ft_read_data(tab, lemin, -1, error);
	return (1);
}
