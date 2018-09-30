/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:53:13 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/23 15:53:39 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define P p->size

void	ft_putwchar(wchar_t chr)
{
	if (chr > 0x10ffff || (chr >= 0xd800 && chr <= 0xdfff) || chr < 0)
		;
	else if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) | 0xC0);
		ft_putchar((chr & 0x3F) | 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) | 0xE0);
		ft_putchar((chr >> 6) | 0xC0);
		ft_putchar((chr & 0x3F) | 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) | 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) | 0x80);
		ft_putchar(((chr >> 6) & 0x3F) | 0x80);
		ft_putchar((chr & 0x3F) | 0x80);
	}
}

void	ft_wchar(t_printf *p)
{
	wint_t	c;
	char	*str;

	str = (char *)malloc(sizeof(char) * 5);
	c = va_arg(p->ap, wint_t);
	p->len = (c == 0) ? p->len + 1 : p->len;
	ft_bzero(str, 5);
	if (c >= 0)
		ft_conv_wchar(p, c, str);
	else
		p->error = -1;
	if (p->error != -1 && p->txt == 1)
		ft_print_buf(p);
	if ((P = (P - ft_strlen(str))) > 0 && p->flag[LESS] == 0 && p->error != -1)
		ft_put_space(p, 2);
	if (p->error != -1)
	{
		p->buf = ft_strdup(str);
		ft_print_buf(p);
	}
	if (p->size > 0 && p->flag[LESS] == 1 && p->error != -1)
		ft_put_space(p, 2);
	free(str);
}

void	ft_char(t_printf *p)
{
	int c;

	if (p->txt == 1)
		ft_print_buf(p);
	c = va_arg(p->ap, int);
	if (p->size-- > 0 && p->flag[LESS] == 0)
		ft_put_space(p, 2);
	ft_putchar(c);
	p->len++;
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}

int		ft_char_size(int a, int nb)
{
	if (a <= 8)
		nb += 1;
	else if (a > 8 && a <= 11)
		nb += 2;
	else if (a > 11 && a <= 16)
		nb += 3;
	else if (a > 16 && a <= 21)
		nb += 4;
	return (nb);
}

int		ft_wstrlen(wchar_t *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i += ft_get_a(*str);
		str++;
	}
	return (i);
}
