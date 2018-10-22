/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_nodelist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:58:18 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:58:19 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodelist	*cpy_nodelist(t_nodelist *src, t_nodelist *dest)
{
	t_node		*tmp;

	dest->length = 0;
	tmp = src->start;
	while (tmp)
	{
		add_node(dest, new_node(tmp->nb));
		tmp = tmp->next;
	}
	return (dest);
}
