/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_li.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:05 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/21 17:16:38 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_zero_size(t_printf *p, long i)
{
	int		zeros;
	long	tmp;
	char	*str;

	tmp = (i < 0) ? -i : i;
	str = ft_ltoa(tmp);
	zeros = p->precision - ft_strlen(str);
	zeros = (p->dot == 1 && i == 0) ? zeros + 1 : zeros;
	zeros = (zeros < 0) ? 0 : zeros;
	free(str);
	str = ft_ltoa(i);
	tmp = (p->flag[MORE] == 1 && i >= 0) ? 1 : 0;
	p->size = p->size - (zeros + ft_strlen(str) + tmp);
	free(str);
	p->size = (p->dot == 1 && i == 0) ? p->size + 1 : p->size;
	return (zeros);
}

void	ft_long2(t_printf *p, long i, int zeros)
{
	if (p->flag[MORE] == 1 && i >= 0)
	{
		ft_putchar('+');
		p->len++;
	}
	if (i < 0 && i != LONG_MIN)
	{
		ft_putchar('-');
		p->len++;
		i = -i;
	}
	if (p->size > 0 && (p->flag[ZERO] == 1 && p->precision == 0))
		ft_put_space(p, 1);
	if (zeros > 0)
		ft_put_precision(p, zeros);
	if (!(p->dot == 1 && i == 0))
	{
		p->buf = ft_ltoa(i);
		ft_print_buf(p);
	}
	if (p->size > 0 && (p->flag[LESS] == 1))
		ft_put_space(p, 2);
}

void	ft_long(t_printf *p)
{
	long	i;
	int		zeros;

	if (p->txt == 1)
		ft_print_buf(p);
	i = va_arg(p->ap, long int);
	zeros = ft_zero_size(p, i);
	if (p->flag[SPACE] == 1 && i >= 0 && p->flag[MORE] == 0)
		p->size--;
	if (p->size > 0 && (p->flag[ZERO] != 1 ||
				p->precision > 0) && (p->flag[LESS] != 1))
		ft_put_space(p, 2);
	if (p->flag[SPACE] == 1 && i >= 0 && p->flag[MORE] == 0)
	{
		ft_putchar(' ');
		p->len++;
	}
	ft_long2(p, i, zeros);
}
