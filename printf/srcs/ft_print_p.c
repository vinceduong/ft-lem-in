/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:27:33 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/10 11:27:35 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptraddr_prec(t_env *op)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = (int)ft_strlen(op->out);
	if (op->flags.press > len)
	{
		tmp = ft_strnew(op->flags.press - len);
		while (++i < op->flags.press - len)
			tmp[i] = '0';
		res = ft_strjoin(tmp, op->out);
		free(op->out);
		free(tmp);
		op->out = res;
	}
	tmp = ft_strjoin("0x", op->out);
	free(op->out);
	op->out = tmp;
}

void	ft_print_ptraddr_width(t_env *op)
{
	int len;

	op->flags.width = op->flags.width - 1;
	len = ft_strlen(op->out);
	while (--op->flags.width > len)
		op->ret += op->flags.zero == 1 ? write(1, "0", 1) : write(1, " ", 1);
}

void	ft_print_ptraddr(t_env *op, char type)
{
	if (op->flags.zero && op->flags.press == -1)
		op->flags.press = op->flags.width - 2;
	if (type == 'p')
		ft_strlower(op->out);
	if (op->flags.minus)
	{
		op->ret += write(1, op->out, ft_strlen(op->out));
		ft_print_ptraddr_width(op);
	}
	else
	{
		ft_print_ptraddr_width(op);
		op->ret += write(1, op->out, ft_strlen(op->out));
	}
	++op->i;
	free(op->out);
}
