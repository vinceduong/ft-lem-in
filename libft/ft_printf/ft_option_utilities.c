/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_uilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:56:52 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/23 15:51:10 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_opt_flag(t_printf *p)
{
	if (F == '#')
	{
		p->flag[POUND] = 1;
		p->idx2++;
	}
	else if (F == '0')
	{
		p->flag[ZERO] = 1;
		p->idx2++;
	}
	else if (F == '-')
	{
		p->flag[LESS] = 1;
		p->idx2++;
	}
	else if (F == '+')
	{
		p->flag[MORE] = 1;
		p->idx2++;
	}
	else if (F == ' ')
	{
		p->flag[SPACE] = 1;
		p->idx2++;
	}
}

void		ft_opt_precision_size(t_printf *p)
{
	int		i;
	char	*str;

	i = 0;
	if (F == '.')
	{
		p->dot = 1;
		p->idx2++;
	}
	while (ft_isdigit(p->format[i]) && p->format[i] != '\0')
		i++;
	if (!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(p->format[p->idx2]) && p->format[i] != '\0')
	{
		str[i] = p->format[p->idx2];
		p->idx2++;
		i++;
	}
	str[i] = '\0';
	p->dot == 1 ? (p->precision = ft_atoi(str))
		: (p->size = ft_atoi(str));
	free(str);
}

void		ft_opt_modif(t_printf *p)
{
	if (F == 'h' && p->format[p->idx2 + 1] == 'h')
	{
		p->modif[HH] = 1;
		p->idx2++;
	}
	else if (F == 'h')
		p->modif[H] = 1;
	else if (F == 'l' && p->format[p->idx2 + 1] == 'l')
	{
		p->modif[LL] = 1;
		p->idx2++;
	}
	else if (F == 'l')
		p->modif[L] = 1;
	else if (F == 'j')
		p->modif[J] = 1;
	else if (F == 'z')
		p->modif[Z] = 1;
	p->idx2++;
}
