/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dead_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:58:51 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:58:52 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_living_childs(t_lemin *l, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (j < l->m.nbcases)
	{
		count += l->m.graph[i][j] && (l->m.graph[j][j] != -1) ? 1 : 0;
		j++;
	}
	return (count);
}

void	map_dead_nodes(t_lemin *l)
{
	int		i;
	int		ended;

	ended = 1;
	i = 0;
	while (i < l->m.nbcases)
	{
		if (i && i != l->m.nbcases - 1 && l->m.graph[i][i] != -1)
		{
			if (count_living_childs(l, i) < 2)
			{
				l->m.graph[i][i] = -1;
				ended = 0;
			}
		}
		i++;
	}
	if (!ended)
		map_dead_nodes(l);
	return ;
}
