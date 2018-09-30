/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:47:43 by cammapou          #+#    #+#             */
/*   Updated: 2018/06/14 12:05:08 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_len(char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void		ft_sub(char **line, char **str)
{
	char	*s;

	s = NULL;
	*line = ft_strsub(*str, 0, ft_len(*str, '\n'));
	s = ft_strsub(*str, ft_len(*str, '\n') + 1,
		ft_strlen(&str[0][ft_len(*str, '\n')]));
	ft_strdel(str);
	*str = s;
}

int			get_next_line(const int fd, char **line)
{
	char					buff[BUF_SIZE + 1];
	static	char			*str[OPEN_MAX];
	char					*tmp;
	int						ret;

	ret = 0;
	if (line == NULL || fd < 0 || BUF_SIZE < 0 || read(fd, "", 0) < 0 ||
			fd > OPEN_MAX)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while (!(ft_strchr(str[fd], '\n')))
	{
		ret = read(fd, buff, BUF_SIZE);
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
	}
	if (ft_strlen(str[fd]) == 0)
		return (0);
	ft_sub(line, &str[fd]);
	return (1);
}
