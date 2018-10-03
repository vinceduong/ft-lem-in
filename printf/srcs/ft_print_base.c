/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:27:01 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/10 11:54:40 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base_pre(t_env *op, char type, long val)
{
	if (op->flags.hash && op->out[0] != '\0' && val != 0)
	{
		op->ret += (type == 'o' || type == 'O') ? write(1, "0", 1) : 0;
		op->ret += (type == 'x') ? write(1, "0x", 2) : 0;
		op->ret += (type == 'X') ? write(1, "0X", 2) : 0;
	}
	else if ((type == 'o' || type == 'O') && op->flags.hash &&
		op->flags.press >= 0)
		op->ret += write(1, "0", 1);
}

void	ft_print_base_width(t_env *op, char type)
{
	int	i;
	int len;

	i = -1;
	len = ft_strlen(op->out);
	if (op->flags.hash && (op->out[0] != '\0' && op->out[0] != '0'))
	{
		op->flags.width -= ((type == 'o' || type == 'O') ? 1 : 0);
		op->flags.width -= ((type == 'x' || type == 'X') ? 2 : 0);
	}
	if (op->flags.press >= 0)
	{
		while (op->flags.width > op->flags.press + ++i
				&& op->flags.width > len + i)
			op->ret += write(1, " ", 1);
		while (op->flags.width > len + i++)
			op->ret += write(1, "0", 1);
	}
	else
	{
		while (op->flags.width > len + ++i)
			op->ret += (op->flags.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
	}
}

void	ft_check_base_prec(t_env *op, char type)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	len = (int)ft_strlen(op->out);
	if (op->flags.press == 0 && op->out[0] == '0')
		op->out[0] = '\0';
	else if (op->flags.press > len)
	{
		if ((type == 'o' || type == 'O') && op->flags.hash)
			op->flags.press--;
		i = op->flags.press - len;
		tmp = ft_strnew(i);
		while (--i >= 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, op->out);
		free(tmp);
		free(op->out);
		op->out = res;
	}
}

void	ft_print_base(t_env *op, char type, long val)
{
	ft_check_base_prec(op, type);
	if (op->flags.zero)
	{
		ft_print_base_pre(op, type, val);
		ft_print_base_width(op, type);
		op->ret += write(1, op->out, ft_strlen(op->out));
	}
	else if (op->flags.minus)
	{
		ft_print_base_pre(op, type, val);
		op->ret += write(1, op->out, ft_strlen(op->out));
		ft_print_base_width(op, type);
	}
	else
	{
		ft_print_base_width(op, type);
		ft_print_base_pre(op, type, val);
		op->ret += write(1, op->out, ft_strlen(op->out));
	}
	++op->i;
	free(op->out);
}
