/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:16:01 by apoque            #+#    #+#             */
/*   Updated: 2017/11/13 11:30:21 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*tmp;

	tmp = (char *)dest;
	while (len)
	{
		if (*src)
			*tmp++ = *src++;
		else
			*tmp++ = '\0';
		len--;
	}
	return (dest);
}
