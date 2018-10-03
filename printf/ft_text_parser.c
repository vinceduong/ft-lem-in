/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_reader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:32:40 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/23 15:51:32 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_text_parser(t_printf *p)
{
	while (p->format[p->idx1] && p->error != -1)
	{
		p->idx1 = p->idx2;
		p->txt = 0;
		while (p->format[p->idx2] != '%' && p->format[p->idx2] != '\0')
			p->idx2++;
		if (p->idx1 != p->idx2)
			ft_txt(p);
		if (p->format[p->idx2++] == '%')
		{
			ft_init_options(p);
			ft_is_option(p);
			ft_treatment(p);
		}
		if (p->txt == 1 && p->idx1 == ft_strlen((char *)p->format))
			ft_print_buf(p);
	}
}

void		ft_txt(t_printf *p)
{
	char	*tmp;
	int		i;

	i = 0;
	p->txt = 1;
	tmp = (char *)malloc(sizeof(char) * (p->idx2 - p->idx1 + 1));
	tmp[p->idx2 - p->idx1] = '\0';
	while (p->idx1 < p->idx2)
	{
		tmp[i] = p->format[p->idx1];
		p->idx1++;
		i++;
	}
	p->buf = ft_strdup(tmp);
	free(tmp);
}
