/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:10:07 by apoque            #+#    #+#             */
/*   Updated: 2017/11/16 11:00:39 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_char;
	char	*src_char;

	dst_char = (char *)dst;
	src_char = (char *)src;
	if (src <= dst && dst <= src + len)
	{
		i = len;
		while (i > 0)
		{
			dst_char[i - 1] = src_char[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_char[i] = src_char[i];
			i++;
		}
	}
	return (dst);
}
