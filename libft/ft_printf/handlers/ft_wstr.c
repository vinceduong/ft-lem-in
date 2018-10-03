/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 21:22:05 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 21:25:35 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define I str[i]
#define V1 0x10ffff
#define V2 0xd800
#define V3 0xdfff
#define M MB_CUR_MAX
#define P p->precision
#define W ft_wstrlen(str)

int		ft_wchar_len(wchar_t c)
{
	if (c >= 0 && c <= 0x7F)
		return (1);
	else if (c >= 0x80 && c <= 0x7FF)
		return (2);
	else if ((c >= 0x800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF))
		return (3);
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (4);
	else
		return (-1);
}

int		calc_wstrlen(wchar_t *str, int precision, int i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

void	ft_get_lens(t_printf *p, wchar_t *str, int *lwe, int *len_precision)
{
	int	j;
	int	i;
	int	a;
	int	error;

	j = 0;
	i = -1;
	a = 0;
	error = 0;
	while (j < ft_wstrlen(str))
	{
		error = (str[++i] > V1 || (I >= V2 && I <= V3) || I < 0) ? -1 : error;
		a = ft_get_a(str[i]);
		error = ((M == 1 && a > 8) || (M == 2 && a > 11) ||
				(M == 3 && a > 16) || (M == 4 && a > 21)) ? -1 : error;
		j = ft_char_size(a, j);
		*lwe = (error == 0) ? j : *lwe;
	}
	i = -1;
	while (++i < p->precision)
	{
		a = ft_get_a(str[i]);
		*len_precision = ft_char_size(a, *len_precision);
	}
}

void	ft_wstr2(t_printf *p, wchar_t *str)
{
	int		i;
	int		len_precision;
	int		len_without_error;

	i = 0;
	len_without_error = 0;
	len_precision = 0;
	if (p->modif[Z] == -5)
		p->buf = ft_strdup("(null)");
	if (p->error == -1 && p->dot == 1 && p->precision > 0)
		ft_get_lens(p, str, &len_without_error, &len_precision);
	if (p->error != -1 || ((len_without_error >= len_precision) && p->dot == 1))
	{
		i = (p->dot == 1 && P < W) ? calc_wstrlen(str, P, 0) : W;
		p->buf = ft_strndupfree(p->buf, i);
		p->error = 0;
		p->size = p->size - ft_strlen(p->buf);
		if (p->size > 0 && p->flag[LESS] == 0)
			ft_put_space(p, 2);
		ft_print_buf(p);
		if (p->size > 0 && p->flag[LESS] == 1)
			ft_put_space(p, 2);
	}
	else
		free(p->buf);
}

void	ft_wstr(t_printf *p)
{
	int		i;
	wchar_t	*str;
	char	*buf;

	if (p->txt == 1)
		ft_print_buf(p);
	i = 0;
	str = va_arg(p->ap, wchar_t *);
	if (str == NULL || ft_strcmp((char *)str, "(null)") == 0)
		p->modif[Z] = -5;
	else
		while (str[i] != L'\0' && p->modif[Z] != -5)
		{
			buf = (char *)malloc(sizeof(char) * 5);
			ft_bzero(buf, 5);
			ft_conv_wchar(p, str[i], buf);
			i++;
			if (p->buf != NULL)
				p->buf = ft_strjoinfree(p->buf, buf);
			else
				p->buf = ft_strdup(buf);
			free(buf);
		}
	if (i != 0 || p->modif[Z] == -5)
		ft_wstr2(p, str);
}
