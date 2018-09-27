/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:48:19 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/23 15:50:14 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init_options(t_printf *p)
{
	ft_bzero(p->flag, sizeof(char) * 5);
	ft_bzero(p->modif, sizeof(char) * 6);
	p->dot = 0;
	p->precision = 0;
	p->size = 0;
}

void			ft_is_option(t_printf *p)
{
	if (p->format[p->idx1 + 1] == '%' || F == '\0')
		return ;
	while (ft_int_strchar("-0# +hljz.", F) || ((ft_isdigit(F)) && F != '\0'))
	{
		if (ft_int_strchar("-+#0 ", F))
			ft_opt_flag(p);
		if ((ft_isdigit(F) && F != '0') || F == '.')
			ft_opt_precision_size(p);
		if (ft_int_strchar("hljz", F))
			ft_opt_modif(p);
	}
}
