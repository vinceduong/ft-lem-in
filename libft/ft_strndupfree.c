/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:46:53 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:06 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strndupfree(char *to_free, int n)
{
	char		*tmp;
	int			i;
	int			len;

	tmp = ft_strdup(to_free);
	free(to_free);
	len = ft_strlen(tmp);
	len = (len > n) ? n : len;
	to_free = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!to_free)
		return (NULL);
	while (i < len && tmp[i] != '\0')
	{
		to_free[i] = tmp[i];
		i++;
	}
	to_free[i] = '\0';
	return (to_free);
}
