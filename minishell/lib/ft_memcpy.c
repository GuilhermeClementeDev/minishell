/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:50:18 by guclemen          #+#    #+#             */
/*   Updated: 2024/09/26 11:50:20 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*fake_src;

	i = 0;
	dst = (unsigned char *)dest;
	fake_src = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = fake_src[i];
		i++;
	}
	return (dest);
}
