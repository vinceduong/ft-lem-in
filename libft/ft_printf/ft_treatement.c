/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:56:39 by carmenia          #+#    #+#             */
/*   Updated: 2018/08/23 15:53:00 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_treatment(t_printf *p)
{
	int	a;

	a = 1;
	if ((F == 'u' && p->modif[L] != 1 && p->modif[LL] != 1) ||
			((F == 'd' || F == 'i') && p->modif[Z] == 1))
		ft_uint(p);
	else if (F == 'x')
		ft_xint(p);
	else if (F == 'X')
		ft_xmajint(p);
	else if (F == 'o' && p->modif[LL] != 1 && p->modif[L] != 1)
		ft_oint(p);
	else if (F == 'O' || F == 'o')
		ft_omajint(p);
	else if (F == 'D' || ((F == 'd' || F == 'i') &&
				(p->modif[L] == 1 || p->modif[LL] == 1 || p->modif[J] == 1)))
		ft_long(p);
	else if (F == 's' && p->modif[L] != 1)
		ft_str(p);
	else
	{
		a = 0;
		ft_treatment2(p);
	}
	(a == 1) ? p->idx2++ : a--;
}

void		ft_treatment2(t_printf *p)
{
	int	a;

	a = 1;
	if (F == 'i' || F == 'd')
		ft_int(p);
	else if (F == 'S' || (F == 's' && p->modif[L] == 1))
		ft_wstr(p);
	else if (F == 'c' && p->modif[L] == 0)
		ft_char(p);
	else if (F == 'U' || (F == 'u' && (p->modif[L] == 1 || p->modif[LL] == 1)))
		ft_umajint(p);
	else if (F == 'C' || (F == 'c' && p->modif[L] == 1))
		ft_wchar(p);
	else if (F == 'p')
		ft_p(p);
	else if (F == 'b')
		ft_bint(p);
	else if (F == 'B')
		ft_bmajint(p);
	else if (F == '%')
		ft_print_percent(p);
	else
		a = 0;
	if (a == 1)
		p->idx2++;
}
