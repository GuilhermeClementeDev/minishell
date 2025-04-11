/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:20:35 by guclemen          #+#    #+#             */
/*   Updated: 2024/10/18 07:20:36 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_printf_number(int nb)
{
	ft_putnbr_fd(nb, 1);
	if (nb == 0)
		return (1);
	return (get_size(nb));
}
