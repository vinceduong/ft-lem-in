/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 20:08:23 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 20:45:02 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define P p->precision

void	ft_print_b2(t_printf *p, unsigned long u, int zeros)
{
	if (p->size > 0 && p->flag[ZERO] == 1 && p->flag[LESS] != 1 &&
			((p->dot == 0 && p->flag[POUND] != 1) || u == 0))
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && u == 0))
		ft_print_buf(p);
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}

void	ft_print_b(t_printf *p, unsigned long u)
{
	int	zeros;

	zeros = p->precision - ft_strlen(p->buf);
	zeros = (p->dot == 1 && u == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	p->size = p->size - (zeros + ft_strlen(p->buf));
	p->size = (p->dot == 1 && u == 0) ? p->size + 1 : p->size;
	if (p->size > 0 && (p->flag[ZERO] != 1 || P > 0) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	ft_print_b2(p, u, zeros);
}

void	ft_bint2(t_printf *p)
{
	unsigned int		o;
	unsigned short		s;
	unsigned char		a;

	if (p->modif[H] == 1)
	{
		s = (unsigned short)va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(s, "01");
		ft_print_b(p, s);
	}
	else if (p->modif[HH] == 1)
	{
		a = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(a, "01");
		ft_print_b(p, a);
	}
	else
	{
		o = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(o, "01");
		ft_print_b(p, o);
	}
}

void	ft_bint(t_printf *p)
{
	unsigned long long	u;
	size_t				z;

	if (p->txt == 1)
		ft_print_buf(p);
	if (p->modif[Z] == 1)
	{
		z = va_arg(p->ap, size_t);
		p->buf = ft_itoabase_u(z, "01");
		ft_print_b(p, z);
	}
	else if (p->modif[J] == 1)
	{
		u = va_arg(p->ap, unsigned long long);
		p->buf = ft_itoabase_u(u, "01");
		ft_print_b(p, u);
	}
	else
		ft_bint2(p);
}

void	ft_bmajint(t_printf *p)
{
	unsigned long	o;

	if (p->txt == 1)
		ft_print_buf(p);
	if (p->modif[L] == 1)
		o = (unsigned long int)va_arg(p->ap, unsigned long int);
	else
		o = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	p->buf = ft_itoabase_u(o, "01");
	ft_print_b(p, o);
}
