/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:57:56 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:57:56 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodelist	*add_node(t_nodelist *nodelist, t_node *node)
{
	t_node		*tmp;
	int			i;

	tmp = nodelist->start;
	if (!tmp)
	{
		nodelist->start = node;
		nodelist->start->index = 0;
		nodelist->length++;
		return (nodelist);
	}
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	node->index = i;
	tmp->next = node;
	nodelist->length++;
	return (nodelist);
}
