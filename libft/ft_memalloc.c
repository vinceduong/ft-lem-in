/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:43:35 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/10 15:05:32 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int *mem;

	if (!(mem = (void*)malloc(sizeof(mem) * (size))))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
