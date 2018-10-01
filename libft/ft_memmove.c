/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:37:42 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/14 12:33:32 by cammapou         ###   ########.fr       */
=======
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:44:53 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:04 by carmenia         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest < src)
		ft_memcpy(dest, src, len);
	else if (src < dest)
	{
		while (len > 0)
		{
			len--;
			((char*)dest)[len] = ((char*)src)[len];
		}
	}
	return (dest);
}
