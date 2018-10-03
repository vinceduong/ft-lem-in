/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 11:49:31 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/22 21:23:39 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_str(t_printf *p)
{
	char	*str;
	int		len;

	len = -1;
	if (p->txt == 1)
		ft_print_buf(p);
	if (p->dot == 1)
		len = p->precision;
	str = va_arg(p->ap, char *);
	if (str == NULL)
		str = "(null)";
	if (len == -1 && str != NULL)
		p->buf = ft_strdup(str);
	else if (len != -1)
		p->buf = ft_strndup(str, len);
	p->size = p->size - ft_strlen(p->buf);
	if (p->size > 0 && p->flag[LESS] == 0)
		ft_put_space(p, 2);
	ft_print_buf(p);
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}
