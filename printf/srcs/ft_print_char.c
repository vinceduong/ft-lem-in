/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:27:09 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/10 11:27:11 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char_width(t_env *op)
{
	while (op->flags.width-- > 1)
		op->ret += (op->flags.zero == 1 ? write(1, "0", 1) : write(1, " ", 1));
}

void	ft_print_null_char(t_env *op)
{
	while (op->flags.width-- > 1)
		op->ret += (op->flags.zero == 1 ? write(1, "0", 1) : write(1, " ", 1));
	op->ret += write(1, "\0", 1);
	++op->i;
}

void	ft_print_char(t_env *op, char c)
{
	if (op->flags.minus)
	{
		op->ret += write(1, &c, 1);
		ft_print_char_width(op);
	}
	else
	{
		ft_print_char_width(op);
		op->ret += write(1, &c, 1);
	}
	++op->i;
}
