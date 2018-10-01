/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:14:53 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/14 16:04:37 by cammapou         ###   ########.fr       */
=======
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:44:40 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:04 by carmenia         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*str;
	size_t			i;
	unsigned int	tmp;

	i = 0;
	s = (unsigned char*)s1;
	str = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (s[i] != str[i])
		{
			tmp = s[i] - str[i];
			return (tmp);
		}
		i++;
	}
	tmp = s[i] - str[i];
	return (tmp);
}
