/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:58:21 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:58:23 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	cpy_path(t_path *src, t_path *dest, t_node *node)
{
	dest->nodes = cpy_nodelist(src->nodes, dest->nodes);
	dest->curr = src->curr;
	dest->ended = src->ended;
	if (node)
		add_node(dest->nodes, node);
	return (1);
}
