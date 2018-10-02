/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <cammapou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:31:08 by cammapou          #+#    #+#             */
/*   Updated: 2018/09/13 17:37:56 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		comment(t_lemin *lemin, char *line)
{
	while (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			return (0);
		if (!readdata(lemin, line))
			return (0);
		get_next_line(0, &line);
	}
	return (1);
}

int 		check_star_end(t_lemin *lemin, char *line)
{
    if (!ft_strcmp(line, "##start"))
    	{
    		get_next_line(0, &line);
    		if (!comment(lemin, line) || !readrooms(lemin, line))
    			return (0);
        if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
          lemin->start = line;
    		if (!(save_instrus(line, lemin)))
          return (0);
    	}
    	else if (!ft_strcmp(line, "##end"))
    	{
    		get_next_line(0, &line);
    		if (!comment(lemin, line) || !readrooms(lemin, line))
    			return (0);
        if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
          lemin->end = line;
    		if(!(save_instrus(line, lemin)))
          return (0);
    	}
    	return (1);
    }

int 		readdata2(t_lemin *lemin, char *line)
{
	if (line[0] == '#' && line[1] == '#')
	{
    if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
      {
        if(!(check_star_end(lemin, line)))
          return (0);
      }
	}
	return (1);
}
