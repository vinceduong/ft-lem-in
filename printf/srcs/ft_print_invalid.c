/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_invalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:02:53 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/10 12:02:54 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_invalid_width(t_env *op)
{
	while (op->flags.width-- > 0)
		op->ret += (op->flags.zero == 1 ?
		write(1, "0", 1) : write(1, " ", 1));
}

void	ft_print_invalid_spec(t_env *op, char c)
{
	if (op->flags.minus)
	{
		op->ret += write(1, &c, 1);
		ft_print_invalid_width(op);
	}
	else
	{
		ft_print_invalid_width(op);
		op->ret += write(1, &c, 1);
	}
	++op->i;
}
