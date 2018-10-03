/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:57:17 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/03 11:12:51 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_file	*new_link(int fd)
{
	t_file	*list;

	list = (t_file *)malloc(sizeof(t_file));
	if (list == NULL)
		return (NULL);
	list->fd = fd;
	list->read = NULL;
	list->next = NULL;
	return (list);
}

static t_file	*start_list(int fd, t_file **list)
{
	t_file	*tmp;

	if (*list == NULL)
	{
		*list = new_link(fd);
		tmp = *list;
		tmp->next = NULL;
	}
	else
	{
		tmp = *list;
		while (tmp->next != NULL && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp->fd != fd && tmp->next == NULL)
		{
			tmp->next = new_link(fd);
			tmp = tmp->next;
		}
	}
	return (tmp);
}

static int		concat(char **reste, char **buff, int *ret)
{
	char	*new;

	new = NULL;
	if (*ret < 0)
		return (-1);
	(*buff)[*ret] = '\0';
	if (*reste == NULL)
		new = ft_strdup(*buff);
	else
	{
		new = ft_strjoin(*reste, *buff);
		ft_strdel(reste);
	}
	*reste = new;
	return (0);
}

static void		find_next_line(int *ret, char ***line, char **r, char *endlr)
{
	char	*tes;

	*ret = 1;
	**line = ft_strsub(*r, 0, endlr - *r);
	if (**line == NULL)
		return ;
	tes = ft_strsub(*r, endlr - *r + 1, ft_strlen(endlr));
	if (tes == NULL)
		return ;
	ft_strcpy(*r, tes);
	ft_strdel(&tes);
}

int				get_next_line(const int fd, char **line)
{
	char			*buff;
	int				ret;
	static t_file	*list;
	t_file			*tmp;

	ret = 0;
	if (BUFF_SIZE <= 0 || !line || !(tmp = start_list(fd, &list))
			|| !(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (tmp->read == NULL || (!(ft_strchr(tmp->read, '\n'))
				&& (ret = read(fd, buff, BUFF_SIZE))))
	{
		if (concat(&tmp->read, &buff, &ret) == -1)
			return (-1);
	}
	ft_strdel(&buff);
	if (tmp->read && ft_strchr(tmp->read, '\n'))
		find_next_line(&ret, &line, &tmp->read, ft_strchr(tmp->read, '\n'));
	else if (!ft_strchr(tmp->read, '\n') && ft_strlen(tmp->read))
	{
		*line = ft_strdup(tmp->read);
		ft_strdel(&(tmp->read));
		return ((ret == 0) ? 1 : 0);
	}
	return (ret > 0 || ft_strlen(tmp->read));
=======
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
>>>>>>> experimental_parse
}
