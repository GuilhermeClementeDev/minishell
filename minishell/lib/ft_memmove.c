/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:14:10 by guclemen          #+#    #+#             */
/*   Updated: 2024/09/30 10:14:35 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*fake_src;

	dst = (unsigned char *)dest;
	fake_src = (unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			dst[n - 1] = fake_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
