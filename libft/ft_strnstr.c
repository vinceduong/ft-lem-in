/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:41:06 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/23 12:38:39 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		c;
	char		*s;

	s = (char*)s1;
	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return (&s[i]);
	while (s[i] != '\0' && i < len)
	{
		j = i;
		c = 0;
		while (s[j] == s2[c] && i + c < len)
		{
			j++;
			c++;
			if (s2[c] == '\0')
				return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
