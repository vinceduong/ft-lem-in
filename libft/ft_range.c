/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:47:30 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/23 11:06:53 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_range(int min, int max)
{
	int		*tab;
	int		i;
	int		len;
	int		j;

	if (min >= max)
		return (NULL);
	i = 0;
	j = min;
	len = max - min;
	tab = (int*)malloc(sizeof(int) * (len));
	while (i < len)
	{
		tab[i] = j;
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}
