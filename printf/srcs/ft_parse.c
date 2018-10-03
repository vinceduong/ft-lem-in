/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:26:52 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/18 12:26:07 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flag(t_flags *flags)
{
	flags->space = 0;
	flags->plus = 0;
	flags->neg = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->press = -1;
	flags->width = 0;
}

void	ft_get_mod(const char *restrict fmt, t_env *op)
{
	if (fmt[op->i] == 'h' && fmt[op->i + 1] != 'h' && op->mod == pf_nomod)
		op->mod = pf_h;
	else if (fmt[op->i] == 'h' && fmt[op->i + 1] == 'h' && op->mod == pf_nomod)
	{
		op->mod = pf_hh;
		++op->i;
	}
	else if (fmt[op->i] == 'l' && fmt[op->i + 1] != 'l')
		op->mod = pf_l;
	else if (fmt[op->i] == 'l' && fmt[op->i + 1] == 'l')
	{
		op->mod = pf_ll;
		++op->i;
	}
	else if (fmt[op->i] == 'z')
		op->mod = pf_z;
	else if (fmt[op->i] == 'j')
		op->mod = pf_j;
}

void	ft_get_prec(const char *restrict fmt, t_env *op)
{
	if (op->flags.press >= 0)
	{
		++op->i;
		return ;
	}
	else if (fmt[op->i] == '.')
	{
		++op->i;
		op->flags.press = ft_atoi(fmt + op->i);
		while ((fmt[op->i]) >= '0' && fmt[op->i] <= '9')
			++op->i;
	}
}

void	ft_option(const char *restrict fmt, t_env *op)
{
	ft_init_flag(&op->flags);
	op->mod = pf_nomod;
	while (ft_strchr(" #+-.0123456789hjlz", fmt[op->i]))
	{
		fmt[op->i] >= 'h' && fmt[op->i] <= 'z' ? ft_get_mod(fmt, op) : 0;
		fmt[op->i] == ' ' ? op->flags.space = 1 : 0;
		fmt[op->i] == '-' ? op->flags.minus = 1 : 0;
		fmt[op->i] == '+' ? op->flags.plus = 1 : 0;
		fmt[op->i] == '#' ? op->flags.hash = 1 : 0;
		fmt[op->i] == '0' ? op->flags.zero = 1 : 0;
		if (fmt[op->i] == '.')
			ft_get_prec(fmt, op);
		else if (fmt[op->i] >= '1' && fmt[op->i] <= '9' && op->flags.press < 0)
		{
			op->flags.width = ft_atoi(fmt + op->i);
			while (fmt[op->i] >= '0' && fmt[op->i] <= '9')
				++op->i;
		}
		else
			++op->i;
	}
}

void	ft_get_spec(const char *restrict fmt, t_env *op)
{
	if (fmt[op->i] == '%' || !fmt[op->i])
		ft_spec_percent(op);
	else if ((fmt[op->i] == 'd' || fmt[op->i] == 'i') && op->mod != pf_z)
		ft_spec_int(op);
	else if (fmt[op->i] == 'u' || fmt[op->i] == 'U' || fmt[op->i] == 'D' ||
			((fmt[op->i] == 'd' || fmt[op->i] == 'i') && op->mod == pf_z))
		ft_spec_unsint(op, fmt[op->i]);
	else if ((fmt[op->i] == 'c' || fmt[op->i] == 's') && op->mod != pf_l)
		ft_spec_char(op, fmt[op->i]);
	else if (((fmt[op->i] == 'c' || fmt[op->i] == 's') && op->mod == pf_l) ||
			fmt[op->i] == 'C' || fmt[op->i] == 'S')
		ft_spec_wchar(op, fmt[op->i]);
	else if (ft_strchr("oxOX", fmt[op->i]))
		ft_spec_base(op, fmt[op->i]);
	else if (fmt[op->i] == 'p' || fmt[op->i] == 'P')
		ft_spec_ptraddr(op, fmt[op->i]);
	else if (fmt[op->i] != '\0' && op->mod != pf_l && op->mod != pf_h)
		ft_print_invalid_spec(op, fmt[op->i]);
}
