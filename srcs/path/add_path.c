/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:58:05 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:59:20 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*add_path(t_pathlist *pathlist, t_path *path)
{
	t_path	*tmp;

	tmp = pathlist->start;
	if (!tmp)
	{
		pathlist->start = path;
		path->next = NULL;
		path->previous = NULL;
		return (pathlist);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = path;
	path->previous = tmp;
	path->next = NULL;
	return (pathlist);
}
