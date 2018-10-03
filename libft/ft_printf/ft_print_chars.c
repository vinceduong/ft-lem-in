/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:00:54 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/23 15:50:46 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_buf(t_printf *p)
{
	p->len = p->len + ft_strlen(p->buf);
	ft_putstr(p->buf);
	if (p->buf != NULL && F != 'c' && F != 'C')
	{
		free(p->buf);
		p->buf = NULL;
	}
	else
		free(p->buf);
}

void		ft_print_percent(t_printf *p)
{
	if (p->txt == 1)
		ft_print_buf(p);
	p->size--;
	if (p->size > 0 && p->flag[ZERO] == 1 && p->flag[LESS] != 1)
		ft_put_space(p, 1);
	if (p->size > 0 && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	ft_putchar('%');
	p->len++;
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}

void		ft_put_space(t_printf *p, int flag)
{
	while (p->size != 0)
	{
		if (flag == 1)
			ft_putchar('0');
		if (flag == 2)
			ft_putchar(' ');
		p->len++;
		p->size--;
	}
}

void		ft_put_precision(t_printf *p, int zeros)
{
	while (zeros != 0)
	{
		ft_putchar('0');
		p->len++;
		zeros--;
	}
}
