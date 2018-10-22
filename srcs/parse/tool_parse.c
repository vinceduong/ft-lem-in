/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:57:45 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:57:46 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clean(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

int		ft_intlen(int nb)
{
	int i;

	i = 1;
	if (nb >= 0 && nb <= 9)
		return (i + 1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int		ft_check_value_2(t_lemin *lemin, int *error_tab)
{
	lemin->m.nbcases = error_tab[4];
	lemin->nb_link = error_tab[3];
	lemin->a.nbants = error_tab[2];
	if (error_tab[1] == error_tab[0])
		return (0);
	if (lemin->m.nbcases < 2 || lemin->nb_link < 1 || lemin->a.nbants <= 0 || \
			error_tab[1] == 0 || error_tab[0] == 0)
		return (0);
	return (1);
}

int		*ft_create_error_tab(void)
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

int		ft_check_room(char **tab, int i)
{
	int		j;
	char	*tb;

	tb = NULL;
	j = 0;
	if (ft_chrstr(tab[i], ' ') == 1 && ft_chrstr(tab[i], '#') == 0)
	{
		tb = tab[i++];
		while (tb[j] != ' ')
			j++;
		j++;
		while (tb[j])
		{
			if ((tb[j] >= 32 && tb[j] <= 47) || (tb[j] >= 58 && tb[j] >= 64) \
					|| (tb[j] == 97))
				j++;
			if (!ft_isdigit(tb[j]))
				return (0);
			j++;
		}
	}
	return (1);
}
