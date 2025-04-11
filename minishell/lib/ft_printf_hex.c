/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:21:46 by guclemen          #+#    #+#             */
/*   Updated: 2024/10/18 07:21:48 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rprint(char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (c == 'X')
		{
			s[i] = ft_toupper(s[i]);
			write(1, &s[i], 1);
		}
		if (c == 'x')
			write(1, &s[i], 1);
		i--;
	}
}

int	ft_printf_hex(unsigned int nb, int c)
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
		ft_rprint(arr, c);
	}
	return (i);
}
