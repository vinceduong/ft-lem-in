/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 20:54:53 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/21 21:23:00 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_strstr(const char *src, const char *find)
{
	size_t	len;

	len = ft_strlen(find);
	if (*find == '\0' || !find)
		return (0);
	while (*src)
	{
		if (ft_strncmp(src, find, len) == 0)
			return (1);
		src++;
	}
	return (0);
}
