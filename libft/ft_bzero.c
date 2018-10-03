/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2018/09/30 15:42:28 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/03 11:12:27 by carmenia         ###   ########.fr       */
=======
/*   Created: 2017/11/08 16:26:02 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/13 19:17:06 by cammapou         ###   ########.fr       */
>>>>>>> experimental_parse
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
