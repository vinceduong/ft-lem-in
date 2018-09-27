/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:15:39 by apoque            #+#    #+#             */
/*   Updated: 2017/11/13 11:35:28 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	char	*tmp;

	tmp = (char *)dest;
	while (*tmp != '\0')
		tmp++;
	while (len-- > 0 && *src != '\0')
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
