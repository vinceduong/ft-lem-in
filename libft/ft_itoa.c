/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:22:21 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/17 16:37:24 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n, int *neg)
{
	int		i;

	i = 1;
	*neg = 0;
	if (n < 0)
	{
		*neg = 1;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (*neg == 1)
		i = i + 1;
	return (i);
}

char			*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*str;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(n, &neg);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = size;
	if (neg == 1)
		n = -n;
	while (i >= 0)
	{
		str[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	str[size] = '\0';
	return (str);
}
