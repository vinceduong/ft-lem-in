/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:30:37 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/16 16:01:21 by cammapou         ###   ########.fr       */
=======
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:47:27 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:07 by carmenia         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	size_t			size;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == 32)
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[len] == '\n' || s[len] == '\t' || s[len] == 32)
		len--;
	size = len - i + 1;
	return (ft_strsub(s, i, size));
}
