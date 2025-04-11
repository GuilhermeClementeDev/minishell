/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:19:48 by guclemen          #+#    #+#             */
/*   Updated: 2024/10/18 07:19:50 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verify(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_printf_char(va_arg(args, int));
	if (c == 's')
		size = ft_printf_string(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		size = ft_printf_number(va_arg(args, int));
	if (c == 'u')
		size = ft_printf_unsigned_num(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		size = ft_printf_hex(va_arg(args, unsigned int), c);
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		size = 1;
	}
	if (c == 'p')
		size = ft_printf_pointer(va_arg(args, unsigned long));
	return (size);
}

static int	ft_write(const char *s, va_list args)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			size += ft_verify(s[i + 1], args);
			i += 2;
		}
		if (s[i] && s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			size++;
			i++;
		}
	}
	return (size);
}

int	ft_printf(const char *s, ...)
{
	int		size;
	va_list	args;

	if (!s)
		return (-1);
	if (!ft_strchr(s, '%'))
		return (ft_printf_string((char *)s));
	va_start(args, s);
	size = ft_write(s, args);
	va_end(args);
	return (size);
}
