/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:28:26 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/18 12:24:38 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec_wchar(t_env *op, char type)
{
	wchar_t *ws;
	wchar_t wc;

	op->flags.minus ? op->flags.zero = 0 : 0;
	if (type == 's' || type == 'S')
	{
		ws = va_arg(op->ap, wchar_t *);
		if (ws == NULL)
			return (ft_print_null_str(op));
		ft_print_wstr(op, ws);
	}
	else if (type == 'c' || type == 'C')
	{
		wc = va_arg(op->ap, wchar_t);
		if (wc == 0)
			return (ft_print_null_char(op));
		ft_print_wchar(op, wc);
	}
}

void	ft_spec_ptraddr(t_env *op, char type)
{
	long				value;
	unsigned	long	p;

	value = va_arg(op->ap, long);
	p = (unsigned long)value;
	op->ret += write(1, "0x", 2);
	if (op->flags.press == 0)
		op->out = ft_strdup("\0");
	else
		op->out = ft_ltoa_base(p, 16);
	ft_print_ptraddr(op, type);
}

void	ft_spec_percent(t_env *op)
{
	if (op->flags.minus)
	{
		op->ret += write(1, "%", 1);
		while (op->flags.width-- > 1)
			op->ret += write(1, " ", 1);
	}
	else
	{
		while (op->flags.width-- > 1)
			op->ret += (op->flags.zero ?
			write(1, "0", 1) : write(1, " ", 1));
		op->ret += write(1, "%", 1);
	}
	++op->i;
}
