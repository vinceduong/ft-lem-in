/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:59:00 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:59:02 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	paths(t_lemin *l)
{
	t_pathlist	*paths;

	if (!(paths = init_pathlist()))
		return (0);
	map_dead_nodes(l);
	if (!(paths = find_pathlist(l, paths)))
		return (0);
	if (!paths->start)
		return (0);
	if (!(fill_paths(l, paths)))
		return (0);
	return (1);
}
