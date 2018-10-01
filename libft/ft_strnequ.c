/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:48:43 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/13 19:34:13 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (s1 == NULL && s2 != NULL)
		return (0);
	if (s1 != NULL && s2 == NULL)
		return (0);
	if (s1 == NULL && s2 == NULL)
		return (1);
	while (s1[i] && s2[i] && n > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		if (n == 1)
			return (1);
		i++;
		n--;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
