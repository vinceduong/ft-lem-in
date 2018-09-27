/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:20:17 by apoque            #+#    #+#             */
/*   Updated: 2017/11/18 15:20:44 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	int	res;

	res = 1;
	if (nb && power && power > 0)
	{
		while (power > 0)
		{
			res = res * nb;
			power--;
		}
		return (res);
	}
	if (power == 0)
		return (1);
	else
		return (0);
}
