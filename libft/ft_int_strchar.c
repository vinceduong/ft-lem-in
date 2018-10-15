/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:42:39 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/15 12:02:12 by carmenia         ###   ########.fr       */
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
