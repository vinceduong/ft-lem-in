/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:17:53 by apoque            #+#    #+#             */
/*   Updated: 2017/11/08 19:32:21 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int	start;
	int	end;

	start = 0;
	if (!s)
		return (NULL);
	end = (int)ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n') &&
			s[start] != '\0')
		start++;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') &&
			end > start)
		end--;
	return (ft_strsub(s, start, (end - start + 1)));
}
