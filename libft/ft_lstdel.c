/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: cammapou <cammapou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:04:45 by cammapou          #+#    #+#             */
/*   Updated: 2018/07/18 18:08:55 by cammapou         ###   ########.fr       */
=======
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:43:57 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:04 by carmenia         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (*alst && (*del))
	{
		ft_lstdel(&(*alst)->next, (*del));
		ft_lstdelone(alst, (*del));
	}
}
