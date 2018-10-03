/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <cammapou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:42:55 by cammapou          #+#    #+#             */
/*   Updated: 2018/07/18 18:55:09 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_lstmax(t_list *lst)
{
	int	max;

	max = INT_MIN;
	while (lst && lst->content)
	{
		if (((*(int*)lst->content) > max))
			max = (*(int*)lst->content);
		lst = lst->next;
	}
	return (max);
}
