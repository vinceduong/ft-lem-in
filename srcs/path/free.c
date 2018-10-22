/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:58:41 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:58:42 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_node(t_node *node)
{
	if (node)
		free(node);
}

void	free_nodelist(t_nodelist *nodelist)
{
	t_node *tmp;
	t_node *tmp2;

	if (nodelist)
	{
		tmp = nodelist->start;
		while (tmp)
		{
			tmp2 = tmp;
			free_node(tmp);
			tmp = tmp2->next;
		}
		free(nodelist);
	}
}

void	free_path(t_path *path)
{
	if (path)
	{
		free_nodelist(path->nodes);
		free(path);
	}
}

void	free_paths_array(t_path **paths, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free_path(paths[i]);
		i++;
	}
	free(paths);
}

void	free_pathlist(t_pathlist *pathlist)
{
	t_path *tmp;
	t_path *tmp2;

	if (pathlist)
	{
		tmp = pathlist->start;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free_path(tmp2);
		}
		free(pathlist);
	}
}
