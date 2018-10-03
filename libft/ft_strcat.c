/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:45:47 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:05 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*tmp;

	tmp = (char *)dest;
	while (*tmp)
		tmp++;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
