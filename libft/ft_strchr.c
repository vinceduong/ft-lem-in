/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:12:48 by apoque            #+#    #+#             */
/*   Updated: 2017/11/13 11:57:48 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char	*tmp;
	char	ch;

	tmp = (char *)str;
	ch = (char)c;
	while (*tmp != ch)
	{
		if (*tmp == '\0')
			return (NULL);
		tmp++;
	}
	return (tmp);
}
