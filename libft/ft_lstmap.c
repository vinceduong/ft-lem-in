/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:05:59 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/21 11:36:19 by cammapou         ###   ########.fr       */
=======
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:44:17 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:04 by carmenia         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(lst))))
		return (NULL);
	if (lst)
	{
		new = f(lst);
		new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
