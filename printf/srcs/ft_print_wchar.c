/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:28:01 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/10 11:28:03 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_wchar(t_env *op, char c)
{
	op->ret += write(1, &c, 1);
}

void	ft_put_wc(t_env *op, wchar_t c)
{
	if (c <= 0x7F)
		ft_put_wchar(op, c);
	else if (c <= 0x7FF)
	{
		ft_put_wchar(op, (c >> 6) + 0xC0);
		ft_put_wchar(op, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_put_wchar(op, ((c >> 12) + 0xE0));
		ft_put_wchar(op, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wchar(op, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_put_wchar(op, (c >> 18) + 0xF0);
		ft_put_wchar(op, ((c >> 12) & 0x3F) + 0x80);
		ft_put_wchar(op, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wchar(op, (c & 0x3F) + 0x80);
	}
}

void	ft_print_wchar_minus(t_env *op, wchar_t ws)
{
	ft_put_wc(op, ws);
	while (op->flags.width-- > 1)
		op->ret += write(1, " ", 1);
}

void	ft_print_wchar(t_env *op, wchar_t ws)
{
	if (op->flags.minus)
		ft_print_wchar_minus(op, ws);
	else
	{
		while (op->flags.width-- > 1)
			op->ret += (op->flags.zero ?
			write(1, "0", 1) : write(1, " ", 1));
		ft_put_wc(op, ws);
	}
	++op->i;
}
