/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:14:59 by apoque            #+#    #+#             */
/*   Updated: 2017/11/18 15:23:09 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	const char	*str;
	size_t		i;

	str = (const char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
