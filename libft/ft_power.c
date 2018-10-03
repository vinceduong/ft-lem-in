/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:45:00 by carmenia          #+#    #+#             */
/*   Updated: 2018/09/30 15:48:04 by carmenia         ###   ########.fr       */
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
