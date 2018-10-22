/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:58:44 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:58:45 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nodelist	*init_nodelist(void)
{
	t_nodelist *nl;

	if (!(nl = (t_nodelist*)malloc(sizeof(t_nodelist))))
		return (NULL);
	nl->length = 0;
	nl->start = NULL;
	return (nl);
}

t_node		*new_node(int nb)
{
	t_node *new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}
