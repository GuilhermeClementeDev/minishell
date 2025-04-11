/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:20:19 by guclemen          #+#    #+#             */
/*   Updated: 2024/10/18 07:20:20 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_string(char *s)
{
	if (!s)
		return (ft_printf_string("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
