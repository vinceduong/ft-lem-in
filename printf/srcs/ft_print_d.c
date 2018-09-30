/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:27:17 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/10 11:47:07 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_digit_sign(t_env *op)
{
	if (op->flags.plus || op->flags.space)
		op->ret += (op->flags.plus == 1 ?
		write(1, "+", 1) : write(1, " ", 1));
	else if (op->flags.neg)
		op->ret += write(1, "-", 1);
}

void	ft_print_digit_width(t_env *op)
{
	int i;
	int len;

	i = -1;
	len = ((int)ft_strlen(op->out) > op->flags.press ?
	(int)ft_strlen(op->out) : op->flags.press);
	(op->flags.plus + op->flags.space + op->flags.neg)
		>= 1 ? op->flags.width-- : 0;
	if (op->flags.press >= 0)
	{
		while (op->flags.width - ++i > len)
			op->ret += write(1, " ", 1);
		i = -1;
		while ((int)ft_strlen(op->out) < len - ++i)
			op->ret += write(1, "0", 1);
	}
	else
		while (op->flags.width - ++i > len)
			op->ret += (op->flags.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
}

void	ft_check_digit_sign(t_env *op)
{
	char *tmp;

	if (op->out[0] == '-')
	{
		tmp = ft_strdup(op->out + 1);
		free(op->out);
		op->out = tmp;
		op->flags.space = 0;
		op->flags.plus = 0;
		op->flags.neg = 1;
	}
}

void	ft_check_digit_prec(t_env *op)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	ft_check_digit_sign(op);
	len = (int)ft_strlen(op->out);
	if (op->flags.press == 0 && op->out[0] == '0')
		op->out[0] = '\0';
	else if (op->flags.press > len)
	{
		i = op->flags.press - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, op->out);
		free(tmp);
		free(op->out);
		op->out = res;
	}
}

void	ft_print_digit(t_env *op)
{
	ft_check_digit_prec(op);
	if (op->flags.zero)
	{
		ft_print_digit_sign(op);
		ft_print_digit_width(op);
		op->ret += write(1, op->out, ft_strlen(op->out));
	}
	else if (op->flags.minus)
	{
		ft_print_digit_sign(op);
		op->ret += write(1, op->out, ft_strlen(op->out));
		ft_print_digit_width(op);
	}
	else
	{
		ft_print_digit_width(op);
		ft_print_digit_sign(op);
		op->ret += write(1, op->out, ft_strlen(op->out));
	}
	++op->i;
	free(op->out);
}
