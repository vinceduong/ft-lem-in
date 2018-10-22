/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:58:56 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:58:57 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_pathlist	*new_path_list(t_lemin *l, t_pathlist *paths)
{
	t_path		*tmp;
	t_pathlist	*new_paths;

	if (!paths->start)
		return (NULL);
	tmp = paths->start;
	if (!(new_paths = init_pathlist()))
		return (NULL);
	while (tmp)
	{
		add_new_paths(l, new_paths, tmp);
		tmp = tmp->next;
	}
	free_pathlist(paths);
	return (new_paths);
}
