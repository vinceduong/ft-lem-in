#include "lem_in.h"

/*
start = [0];
end = [1];
ant = [2];
tube = [3];
room = [4];
first_room = [5];
first_tube = [6];
*/

static int ft_check_value(char **tab, t_lemin *lemin, int **error_tab)
{
	lemin->m.nbcases = error_tab[4][0];
	lemin->nb_link = error_tab[3][0];
	lemin->a.nbants = error_tab[2][0];
	if (lemin->m.nbcases < 2 || lemin->nb_link < 1 || lemin->a.nbants <= 0)
		return (0);
	return (1);
}

static int		find_s(char **tab, int i)
{
	while (tab[i][0] == '#' && ft_chrstr(tab[i], ' ') == 0)
		i++;
	return (i);
}

static int	ft_read_data(char **tab, t_lemin *lemin, int i, int **error_tab)
{
	while (tab[++i])
	{
		if (tab[i][0] == '#' && tab[i][1] == '#')
		{
			ft_strcmp(tab[i], "##start") == 0 ? error_tab[0][0] = find_s(tab, i)
			: 0;
			ft_strcmp(tab[i], "##end") == 0 ? error_tab[1][0] = find_s(tab, i)
			: 0;
		}
		else if (tab[i][0] == '#' || tab[i][0] == 'L')
			;
		else if (ft_chrstr(tab[i], ' ') == 0 && ft_chrstr(tab[i], '-') == 1)
		{
			error_tab[6][0] == 0 ? error_tab[6][0] = i : 0;
			error_tab[3][0]++;
		}
		else if (ft_chrstr(tab[i], ' ') == 1 && ft_chrstr(tab[i], '-') == 0 &&
		ft_coord_is_digit(tab[i]) == 1)
		{
			error_tab[5][0] == 0 ? error_tab[5][0] = i : 0;
			error_tab[4][0]++;
		}
		else if (ft_isdigit(tab[i][0]) == 1 && ft_chrstr(tab[i], ' ') == 0 && \
				ft_chrstr(tab[i], '-') == 0)
			error_tab[2][0] = ft_atoi(tab[i]);
		else
			return (0);
	}
	if (!(ft_check_value(tab, lemin, error_tab)))
		return (0);
	ft_create_matrice(tab, lemin, error_tab);
	return (1);
}

static char		**ft_read(char *str, char *line)
{
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, ""))
			return (0);
		str = ft_strjoin(str, line);
		str = ft_strjoin(str, "\n\0");
		ft_strdel(&line);
	}
	ft_putstr(str);
	ft_putchar('\n');
	return (ft_strsplit(str, '\n'));
}

static int		**ft_create_error_tab(void)
{
	int i;
	int **tab;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * 7)))
		exit(0);
	while (i < 7)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * 1)))
			exit(0);
		tab[i][0] = 0;
		tab[i][1] = 0;
		i++;
	}
	return (tab);
}

int				parser(t_lemin *lemin)
{
	char	**tab;
	char	*str;
	char	*line;
	int		**error_tab;

	tab = NULL;
	lemin->r.nbturns = 3;
	if (!(str = ft_memalloc(0)))
		return (0);
	line = NULL;
	error_tab = ft_create_error_tab();
	if (!(tab = ft_read(str, line)))
		return (0);
	if (!(ft_read_data(tab, lemin, -1, error_tab)))
		return (0);
	return (1);
}
