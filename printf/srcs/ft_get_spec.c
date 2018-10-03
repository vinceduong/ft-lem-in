/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cammapou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:25:56 by cammapou          #+#    #+#             */
/*   Updated: 2018/04/18 12:16:50 by cammapou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec_base(t_env *op, char type)
{
	long			tmp;
	unsigned long	val;

	val = 0;
	tmp = va_arg(op->ap, long);
	if (op->mod == pf_hh)
		val = (unsigned char)tmp;
	else if (type == 'O' || op->mod == pf_z || op->mod == pf_ll ||
			op->mod == pf_j || op->mod == pf_l)
		val = (unsigned long)tmp;
	else if (op->mod == pf_h)
		val = (unsigned short)tmp;
	else if (op->mod == pf_nomod)
		val = (unsigned int)tmp;
	(type == 'b' || type == 'B') ? op->out = ft_ultoa_base(val, 2) : 0;
	(type == 'o' || type == 'O') ? op->out = ft_ultoa_base(val, 8) : 0;
	(type == 'x' || type == 'X') ? op->out = ft_ultoa_base(val, 16) : 0;
	if (type == 'b' || type == 'o' || type == 'x')
		ft_strlower(op->out);
	op->flags.minus == 1 ? op->flags.zero = 0 : 0;
	ft_print_base(op, type, (long)val);
}

void	ft_spec_unsint(t_env *op, char type)
{
	long	tmp;

	op->flags.space = 0;
	op->flags.plus = 0;
	tmp = va_arg(op->ap, long);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		op->out = ft_strdup("-9223372036854775808");
	else if (tmp < 0 && op->mod == pf_z && type == 'd')
		op->out = ft_ltoa(tmp);
	else if (type == 'D' || type == 'U' || op->mod == pf_z || op->mod == pf_l ||
			op->mod == pf_j || op->mod == pf_ll)
		op->out = ft_ultoa((unsigned long)tmp);
	else if (op->mod == pf_h)
		op->out = ft_ultoa((unsigned short)tmp);
	else if (op->mod == pf_hh)
		op->out = ft_ultoa((unsigned char)tmp);
	else if (op->mod == pf_nomod && type != 'U')
		op->out = ft_ultoa((unsigned int)tmp);
	ft_print_digit(op);
}

void	ft_spec_char(t_env *op, char type)
{
	char	*stmp;
	int		ctmp;

	op->flags.minus ? op->flags.zero = 0 : 0;
	if (type == 's')
	{
		stmp = va_arg(op->ap, char *);
		if (stmp == NULL)
			return (ft_print_null_str(op));
		op->out = ft_strdup((char*)stmp);
		ft_print_str(op);
	}
	else if (type == 'c')
	{
		ctmp = va_arg(op->ap, int);
		ft_print_char(op, ctmp);
	}
}

void	ft_spec_int(t_env *op)
{
	long	tmp;
	long	i;

	tmp = va_arg(op->ap, long);
	i = (long long)tmp;
	op->flags.minus == 1 ? op->flags.zero = 0 : 0;
	op->flags.press >= 0 ? op->flags.zero = 0 : 0;
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		op->out = ft_strdup("-9223372036854775808");
	else if (op->mod == pf_hh)
		op->out = ft_itoa((char)i);
	else if (op->mod == pf_h)
		op->out = ft_itoa((short)i);
	else if (op->mod == pf_nomod)
		op->out = ft_itoa((int)i);
	else if (op->mod == pf_l || op->mod == pf_j ||
			op->mod == pf_ll)
		op->out = ft_ltoa((long)i);
	ft_print_digit(op);
}
