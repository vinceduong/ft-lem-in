/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:17:24 by apoque            #+#    #+#             */
/*   Updated: 2017/11/13 12:10:24 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *src, const char *find)
{
	size_t	len;

	len = ft_strlen(find);
	if (*find == '\0' || !find)
		return ((char *)src);
	while (*src)
	{
		if (ft_strncmp(src, find, len) == 0)
			return ((char *)src);
		src++;
	}
	return (NULL);
}
