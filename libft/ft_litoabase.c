/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:09:22 by apoque            #+#    #+#             */
/*   Updated: 2018/02/13 21:12:12 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_char_len(unsigned long value, int base)
{
	int	len;

	len = -1;
	if (value == 0)
		return (0);
	while (value != 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char		*ft_litoabase(unsigned long value, int base)
{
	char	*tab;
	char	*dest;
	int		i;

	dest = NULL;
	tab = NULL;
	if (base == 10)
		return (ft_itoa(value));
	if (base < 2 && base > 16)
		return (NULL);
	if ((tab = (char *)malloc(sizeof(char) * 17)))
		ft_strcpy(tab, "0123456789abcdef");
	i = ft_count_char_len(value, base);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	dest[i + 1] = 0;
	while (i >= 0)
	{
		dest[i--] = tab[value % base];
		value = value / base;
	}
	free(tab);
	return (dest);
}
