/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:27:41 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/18 12:21:19 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_width(t_env *op)
{
	int		len;

	len = ft_strlen(op->out);
	while (op->flags.width-- > len)
		op->ret += (op->flags.zero == 1 ? write(1, "0", 1) : write(1, " ", 1));
}

void	ft_print_null_str(t_env *op)
{
	int		len;

	len = (op->flags.press < 0 ? 6 : op->flags.press);
	while (op->flags.width-- > len)
		op->ret += (op->flags.zero == 1 ? write(1, "0", 1) : write(1, " ", 1));
	op->ret += write(1, "(null)", len);
	++op->i;
}

void	ft_print_str(t_env *op)
{
	char	*tmp;

	if (op->flags.press > 0 && op->flags.press < (int)ft_strlen(op->out))
	{
		tmp = ft_strsub(op->out, 0, (op->flags.press));
		free(op->out);
		op->out = tmp;
	}
	if (op->flags.minus)
	{
		op->ret = op->ret + write(1, op->out, ft_strlen(op->out));
		ft_print_width(op);
	}
	else
	{
		ft_print_width(op);
		op->ret = op->ret + write(1, op->out, ft_strlen(op->out));
	}
	op->i++;
	free(op->out);
}
