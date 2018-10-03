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

#include "../../includes/lem_in.h"
/*
int   init_map(t_lemin *lemin)
{
  int i;
  int j;

  i = 0;
  while (i <)
  {
    j =0;
    while(i <)
    {
      if()
        lemin->m.graph[i][j] = 1;
      j++;
    }
    i++;
  }
}*/

int   create_map(t_lemin *lemin)
{
  int i;
  int j;
  int len;

  i = 0;

  len =  lemin->nb_rooms - 1;
  printf("len = %d\n", len);
  if (!(lemin->m.graph = (int**)malloc(sizeof(int*) * (len + 1))))
    return (0);
  while(i < len)
  {
    if (!(lemin->m.graph[i] = (int*)malloc(sizeof(int) * (len + 1))))
      return (0);
    j = 0;
    while (j < len)
      lemin->m.graph[i][j++] = 0;
    lemin->m.graph[i++][j] = '\0';
  }
  lemin->m.graph[i] = NULL;
  printf("graph = %d\n", *lemin->m.graph[0]);
  return (1);
}

/*int		comment(t_lemin *lemin, char *line)
{
	while (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			return (0);
		if (!readdata(lemin, line))
			return (0);
    free(line);
		get_next_line(0, &line);
	}
	return (1);
}*/

int 		check_star_end(t_lemin *lemin, char *line)
{
    if (!ft_strcmp(line, "##start"))
    	{
    		get_next_line(0, &line);
        if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
          lemin->start = 1;
        if (!(readrooms()))
    		if (!(save_instrus(line, lemin)))
          return (0);
    	}
    	else if (!ft_strcmp(line, "##end"))
    	{
    		get_next_line(0, &line);
        if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
          lemin->end = 1;
    		if(!(save_instrus(line, lemin)))
          return (0);
    	}
    	return (1);
    }

int 		read_start_end(t_lemin *lemin, char *line)
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
