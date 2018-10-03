/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:17 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/17 11:51:49 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf p;

	ft_bzero(&p, sizeof(t_printf));
	p.format = format;
	va_start(p.ap, format);
	ft_text_parser(&p);
	va_end(p.ap);
	return ((p.error != -1) ? p.len : -1);
}
