/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:57:41 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:57:42 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_s(char **tab, int i)
{
	while (tab[i] && tab[i][0] == '#' && ft_chrstr(tab[i], ' ') == 0)
		i++;
	if (ft_chrstr(tab[i], ' ') == 0 && ft_chrstr(tab[i], '-') == 1 && \
			ft_chrstr(tab[i], '#') == 0)
		return (0);
	return (i);
}

static int		ft_read_data_suite(char **tab, int i, int *error_tab)
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
	else if (ft_chrstr(tab[i], ' ') == 1 && ft_chrstr(tab[i], '-') == 0)
	{
		error_tab[5] == 0 ? error_tab[5] = i : 0;
		error_tab[4]++;
		if (!(ft_check_room(tab, i)))
			return (0);
	}
	else
		return (0);
	return (1);
}

static int		ft_read_data(char **tab, t_lemin *lemin, int i, int *error_tab)
{
	while (tab[i] != NULL)
	{
		if (ft_read_data_suite(tab, i, error_tab) == 0)
			break ;
		i++;
	}
	if (!(ft_check_value_2(lemin, error_tab)))
		return (0);
	if (!(ft_matrice(tab, lemin, error_tab, error_tab[5])))
		return (0);
	return (1);
}

static char		**ft_read(char *str, char *line)
{
	char **split;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "") || line[0] == 'L')
		{
			free(line);
			break ;
		}
		str = ft_strjoinfree(str, line);
		str = ft_strjoinfree(str, "\n\0");
		free(line);
	}
	write(1, str, ft_strlen(str));
	ft_putchar('\n');
	split = NULL;
	split = ft_strsplit(str, '\n');
	free(str);
	return (split);
}

int				parser(t_lemin *lemin)
{
	char	**tab;
	char	*str;
	char	*line;
	int		*error_tab;

	tab = NULL;
	lemin->r.nbturns = 3;
	if (!(str = ft_memalloc(1)))
		return (0);
	line = NULL;
	error_tab = ft_create_error_tab();
	if (!(tab = ft_read(str, line)))
		return (0);
	if (!(ft_read_data(tab, lemin, 0, error_tab)))
		return (0);
	free(error_tab);
	ft_clean(tab);
	return (1);
}
