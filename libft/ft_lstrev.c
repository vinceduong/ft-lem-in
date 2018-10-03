/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:03:00 by cammapou          #+#    #+#             */
/*   Updated: 2018/06/14 12:03:05 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **lst_a)
{
	t_list	*old_list;
	t_list	*new_list;
	t_list	*tmp;

	old_list = *lst_a;
	new_list = NULL;
	while (old_list)
	{
		tmp = old_list->next;
		old_list->next = NULL;
		ft_lstadd(&new_list, old_list);
		old_list = tmp;
	}
	*lst_a = new_list;
}
