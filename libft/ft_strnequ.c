/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:16:13 by apoque            #+#    #+#             */
/*   Updated: 2017/11/18 13:45:00 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (index < n && s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	if ((s1[index] == '\0' && s2[index] == '\0') || index == n)
		return (1);
	else
		return (0);
}
