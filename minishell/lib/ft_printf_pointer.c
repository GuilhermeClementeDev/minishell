/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:17:21 by guclemen          #+#    #+#             */
/*   Updated: 2024/10/18 07:17:23 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rprint(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		write(1, &s[i], 1);
		i--;
	}
}

static int	ft_printf_bighex(unsigned long nb)
{
	unsigned int	num;
	char			*base;
	char			arr[16];
	int				i;

	base = "0123456789abcdef";
	i = 0;
	if (nb == 0)
	{
		ft_putnbr_fd(nb, 1);
		return (1);
	}
	else
	{
		while (nb)
		{
			num = nb % 16;
			arr[i] = base[num];
			nb = nb / 16;
			i++;
		}
		arr[i] = '\0';
		ft_rprint(arr);
	}
	return (i);
}

int	ft_printf_pointer(unsigned long nb)
{
	int	size;

	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		size = 2;
		ft_putstr_fd("0x", 1);
		size += ft_printf_bighex(nb);
	}
	return (size);
}
