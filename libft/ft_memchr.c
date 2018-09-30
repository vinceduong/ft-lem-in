/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:47:38 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/24 10:49:39 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	unsigned char	i;
	size_t			j;

	str = (const char *)s;
	i = (unsigned char)c;
	j = 0;
	while (j < n)
	{
		if ((unsigned char)str[j] == i)
			return ((void *)&s[j]);
		j++;
	}
	return (NULL);
}
