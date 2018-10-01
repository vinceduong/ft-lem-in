/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:59:36 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/23 11:00:22 by cammapou         ###   ########.fr       */
=======
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:47:08 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:06 by carmenia         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	stock;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		stock = str[i];
		str[i] = str[j];
		str[j] = stock;
		i++;
		j--;
	}
	return (str);
}
