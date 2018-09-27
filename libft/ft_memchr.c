/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:07:59 by apoque            #+#    #+#             */
/*   Updated: 2017/11/13 11:04:16 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (len--)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		else
			tmp++;
	}
	return (NULL);
}
