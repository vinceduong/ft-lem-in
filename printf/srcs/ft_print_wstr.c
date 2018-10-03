/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:28:10 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/18 12:27:22 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_wstr_c(t_env *op, char c)
{
	op->ret += write(1, &c, 1);
}

void	ft_put_wstr(t_env *op, wchar_t c)
{
	if (c <= 0x7F)
		ft_put_wstr_c(op, c);
	else if (c <= 0x7FF)
	{
		ft_put_wstr_c(op, (c >> 6) + 0xC0);
		ft_put_wstr_c(op, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_put_wstr_c(op, ((c >> 12) + 0xE0));
		ft_put_wstr_c(op, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wstr_c(op, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_put_wstr_c(op, (c >> 18) + 0xF0);
		ft_put_wstr_c(op, ((c >> 12) & 0x3F) + 0x80);
		ft_put_wstr_c(op, ((c >> 6) & 0x3F) + 0x80);
		ft_put_wstr_c(op, (c & 0x3F) + 0x80);
	}
}

int		ft_get_wstr_len(wchar_t *wc)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (wc[++i] != 0)
	{
		if (wc[i] <= 0x7F)
			len++;
		else if (wc[i] <= 0x7FF)
			len += 2;
		else if (wc[i] <= 0xFFFF)
			len += 3;
		else if (wc[i] <= 0x10FFFF)
			len += 4;
	}
	return (len);
}

void	ft_print_wstr_minus(t_env *op, wchar_t *wc, int len)
{
	int		i;

	i = -1;
	if (op->flags.press >= 0)
	{
		while (wc[++i] != 0 && i < op->flags.press)
			ft_put_wstr(op, wc[i]);
	}
	else
	{
		while (wc[++i] != 0)
			ft_put_wstr(op, wc[i]);
	}
	while (op->flags.width-- > len)
		op->ret += (op->flags.zero == 1 ?
				write(1, "0", 1) : write(1, " ", 1));
}

void	ft_print_wstr(t_env *op, wchar_t *wc)
{
	int		i;
	int		len;

	i = -1;
	len = (op->flags.press < 0 ? ft_get_wstr_len(wc) : op->flags.press);
	if (op->flags.minus)
		ft_print_wstr_minus(op, wc, len);
	else
	{
		while (op->flags.width-- > len)
			op->ret += (op->flags.zero == 1 ?
					write(1, "0", 1) : write(1, " ", 1));
		if (op->flags.press >= 0)
			while (wc[++i] != 0 && i * 4 < op->flags.press)
				ft_put_wstr(op, wc[i]);
		else
			while (wc[++i] != 0)
				ft_put_wstr(op, wc[i]);
	}
	++op->i;
}
