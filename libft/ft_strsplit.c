/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:05 by cammapou          #+#    #+#             */
/*   Updated: 2017/11/17 17:01:32 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static	int		ft_count_word(char const *s, char c)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (s[i] == c)
		i++;
	if (s[0] != c)
		cpt++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			cpt++;
		i++;
	}
	return (cpt);
}

static	char	**ft_init(char const *s, int *i, int *j, char c)
{
	char	**str;

	*i = 0;
	*j = 0;
	str = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!str)
		return (NULL);
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s)
		return (NULL);
	if ((str = ft_init(s, &i, &j, c)) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			continue ;
		str[j] = (char *)malloc(sizeof(char) * (ft_word_len(&s[i], c) + 1));
		if (!str[j])
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			str[j][k++] = s[i++];
		str[j++][k] = '\0';
	}
	str[j] = NULL;
	return (str);
}
