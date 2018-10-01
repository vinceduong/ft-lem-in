/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:03:28 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/14 13:10:03 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		c;
	char	*s;

	s = (char*)str;
	c = 0;
	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (&s[i]);
	while (s[i] != '\0')
	{
		j = i;
		c = 0;
		while (s[j] == to_find[c])
		{
			j++;
			c++;
			if (to_find[c] == '\0')
				return (&s[i]);
		}
		i++;
	}
	return (0);
}
