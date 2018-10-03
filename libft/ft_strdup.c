/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:46:03 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:05 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	const char	*str;
	char		*dup;
	size_t		i;
	size_t		len;

	str = (const char *)s;
	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
