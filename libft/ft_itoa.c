/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:05:43 by apoque            #+#    #+#             */
/*   Updated: 2018/08/23 15:57:42 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_string_size(long long n, int signe, char **str)
{
	int	size;

	size = 1 + signe;
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	*str = ft_strnew(size);
	return (size);
}

char		*ft_itoa(intmax_t n)
{
	intmax_t	result;
	char		*str;
	int			signe;
	int			size;
	int			i;

	signe = 0;
	i = 0;
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	result = (intmax_t)n;
	if (result < 0)
		signe = 1;
	if (result < 0)
		result = -result;
	size = ft_string_size(result, signe, &str);
	if (signe == 1)
		str[0] = '-';
	while (i < size - signe)
	{
		str[size - 1 - i] = result % 10 + 48;
		result = result / 10;
		i++;
	}
	return (str);
}
