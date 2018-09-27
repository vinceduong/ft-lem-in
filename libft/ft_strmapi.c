/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:18:32 by apoque            #+#    #+#             */
/*   Updated: 2017/11/16 11:18:37 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			size;
	unsigned int	i;

	if (s && f)
	{
		size = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (size + 1));
		i = 0;
		if (str)
		{
			str[size] = '\0';
			while (s[i] != '\0')
			{
				str[i] = (*f)(i, s[i]);
				i++;
			}
			return (&str[0]);
		}
		return (NULL);
	}
	return (NULL);
}
