/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:28:18 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/10 11:28:20 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	t_env op;

	ft_bzero(&op, sizeof(op));
	va_start(op.ap, fmt);
	while (fmt[op.i])
	{
		if (fmt[op.i] == '%' && fmt[op.i + 1] != '%')
		{
			++op.i;
			ft_option(fmt, &op);
			ft_get_spec(fmt, &op);
		}
		else if (fmt[op.i] == '%' && fmt[op.i + 1] == '%')
		{
			op.ret = op.ret + write(1, "%", 1);
			op.i = op.i + 2;
		}
		else
			op.ret += write(1, &fmt[op.i++], 1);
	}
	va_end(op.ap);
	return (op.ret);
}
