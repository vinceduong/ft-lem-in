/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_strchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:42:39 by carmenia          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/10/15 12:02:12 by carmenia         ###   ########.fr       */
=======
/*   Updated: 2018/09/30 15:48:03 by carmenia         ###   ########.fr       */
>>>>>>> d79d8cb6dfba03fc8cf0a10bfaa5c9eea0669405
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
