/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:12:36 by guclemen          #+#    #+#             */
/*   Updated: 2024/09/30 10:12:37 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizenbr(int nb)
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

static void	ft_comarr(char *ptr, int n, int size)
{
	char	num;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			size--;
			ptr[size] = 8 + '0';
			n = (n / 10);
		}
		ptr[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		size--;
		num = (n % 10) + '0';
		ptr[size] = num;
		n = (n / 10);
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	size = ft_sizenbr(n);
	if (n == 0)
		size = 1;
	ptr = (char *) ft_calloc(size + 1, 1);
	if (size + 1 == 1 || ptr == NULL)
		return (NULL);
	ptr[size] = '\0';
	if (n == 0)
		ptr[0] = '0';
	else
		ft_comarr(ptr, n, size);
	return (ptr);
}
