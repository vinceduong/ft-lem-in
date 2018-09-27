/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:16:55 by apoque            #+#    #+#             */
/*   Updated: 2017/11/16 11:17:36 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_word_count(char const *s, char c)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c && s[i] != 0)
			word_count++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (word_count);
}

static const char	*ft_word_fill(char const *s, char c, int word_index,
		char **word_table)
{
	int	word_length;
	int	i;

	word_length = 0;
	while (s[word_length] != c && s[word_length] != 0)
		word_length++;
	if (!(word_table[word_index] =
				(char *)malloc(sizeof(char) * (word_length + 1))))
		return (NULL);
	i = 0;
	while (i < word_length)
	{
		word_table[word_index][i] = s[i];
		i++;
	}
	word_table[word_index][i] = 0;
	return (s + i);
}

char				**ft_strsplit(char const *s, char c)
{
	int		word_count;
	int		word_index;
	char	**word_table;

	if (!s || !c)
		return (NULL);
	word_count = ft_word_count(s, c);
	if (!(word_table = (char **)malloc(sizeof(char *) * word_count + 1)))
		return (NULL);
	word_index = 0;
	while (word_index < word_count)
	{
		while (*s == c)
			s++;
		s = ft_word_fill(s, c, word_index, word_table);
		if (s == NULL)
			return (NULL);
		word_index++;
	}
	word_table[word_index] = NULL;
	return (word_table);
}
