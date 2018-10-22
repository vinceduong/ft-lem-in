/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:56:51 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 14:08:15 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	main_body(t_lemin *lemin)
{
	if (!parser(lemin))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	if (!paths(lemin))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	if (!split_ants(lemin))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	if (!record(lemin))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	if (!display(lemin))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
}

int		main(void)
{
	t_lemin lemin;

	main_body(&lemin);
	return (0);
}
