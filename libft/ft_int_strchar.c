/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 21:23:29 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/21 21:28:29 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_strchar(const char *src, const char find)
{
	while (*src)
	{
		if (*src == find)
			return (1);
		src++;
	}
	return (0);
}
