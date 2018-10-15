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

static int ft_check_value(t_lemin *lemin, int *error_tab)
{
	lemin->m.nbcases = error_tab[4];
	lemin->nb_link = error_tab[3];
	lemin->a.nbants = error_tab[2];
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

static int	ft_read_data(char **tab, t_lemin *lemin, int i, int *error_tab)
{
	while (tab[++i])
	{
		if (tab[i][0] == '#' && tab[i][1] == '#')
		{
			ft_strcmp(tab[i], "##start") == 0 ? error_tab[0] = find_s(tab, i) : 0;
			ft_strcmp(tab[i], "##end") == 0 ? error_tab[1] = find_s(tab, i) : 0;
		}
		else if (tab[i][0] == '#' || tab[i][0] == 'L')
			;
		else if (ft_isdigit(tab[i][0]) == 1 && ft_chrstr(tab[i], ' ') == 0 && \
				ft_chrstr(tab[i], '-') == 0)
			error_tab[2] = ft_atoi(tab[i]);
		else if (ft_chrstr(tab[i], ' ') == 0 && ft_chrstr(tab[i], '-') == 1)
		{
			error_tab[6] == 0 ? error_tab[6] = i : 0;
			error_tab[3]++;
		}
		else if (ft_coord_is_digit(tab[i]) == 1)
		{
			error_tab[5] == 0 ? error_tab[5] = i : 0;
			error_tab[4]++;
		}
		else
			return (0);
	}
	if (!(ft_check_value(lemin, error_tab)))
		return (0);
	ft_putstr("start creation matrice\n");
	ft_create_matrice(tab, lemin, error_tab);
	return (1);
}

static char		**ft_read(char *str, char *line)
{
	char **split;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, ""))
			return (0);
		str = ft_strjoinfree(str, line);
		str = ft_strjoinfree(str, "\n\0");
		free(line);
	}
	ft_putstr(str);
	ft_putchar('\n');
	split = ft_strsplit(str, '\n');
	free(str);
	return (split);
}

static int		*ft_create_error_tab(void)
{
	int i;
	int *tab;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * 7)))
		exit(0);
	while (i != 7)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int				parser(t_lemin *lemin)
{
	char	**tab;
	char	*str;
	char	*line;
	int		*error_tab;

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
	free(error_tab);
	ft_clean(tab);
	free(str);
	return (1);
}
