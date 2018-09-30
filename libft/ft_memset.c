/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:17:46 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/13 19:23:32 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*st;
	size_t	i;

	i = 0;
	st = (char*)s;
	while (i < len)
	{
		st[i] = (unsigned char)c;
		i++;
	}
	return (st);
}
