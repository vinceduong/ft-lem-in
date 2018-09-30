/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:34 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 20:56:56 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define F p->format[p->idx2]
#define P p->precision

void	ft_print_u2(t_printf *p, unsigned long u, int zeros)
{
	if (p->size > 0 && (p->flag[ZERO] == 1 && p->precision == 0))
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && u == 0))
		ft_print_buf(p);
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}

void	ft_print_u(t_printf *p, unsigned long u)
{
	int	zeros;

	zeros = p->precision - ft_strlen(p->buf);
	zeros = (p->dot == 1 && u == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	p->size = p->size - (zeros + ft_strlen(p->buf));
	p->size = (p->dot == 1 && u == 0) ? p->size + 1 : p->size;
	if (p->size > 0 && (p->flag[ZERO] != 1 || P > 0) && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	ft_print_u2(p, u, zeros);
}

void	ft_uint2(t_printf *p)
{
	unsigned int	u;
	unsigned char	a;

	if (p->modif[HH] == 1 && F == 'u')
	{
		a = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(a, "0123456789");
		ft_print_u(p, a);
	}
	else
	{
		u = va_arg(p->ap, unsigned int);
		p->buf = ft_itoabase_u(u, "0123456789");
		ft_print_u(p, u);
	}
}

void	ft_uint(t_printf *p)
{
	size_t			z;
	uintmax_t		x;

	if (p->txt == 1)
		ft_print_buf(p);
	if (p->modif[Z] == 1)
	{
		z = va_arg(p->ap, size_t);
		p->buf = ft_itoabase_u(z, "0123456789");
		if (z > UINT_MAX && F != 'u')
			p->buf = ft_itoa(z);
		ft_print_u(p, z);
	}
	else if (p->modif[J] == 1)
	{
		x = va_arg(p->ap, uintmax_t);
		p->buf = ft_itoabase_u(x, "0123456789");
		ft_print_u(p, x);
	}
	else
		ft_uint2(p);
}

void	ft_umajint(t_printf *p)
{
	unsigned long	u;

	if (p->txt == 1)
		ft_print_buf(p);
	if (p->modif[L] == 1)
		u = (unsigned long int)va_arg(p->ap, unsigned long int);
	else
		u = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	p->buf = ft_itoabase_u(u, "0123456789");
	ft_print_u(p, u);
}
