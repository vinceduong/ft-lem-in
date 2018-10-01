/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:47:04 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/13 19:22:37 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*s;
	size_t	i;

	i = 0;
	dst = (char*)dest;
	s = (char*)src;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
