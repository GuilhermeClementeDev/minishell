/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:15:01 by guclemen          #+#    #+#             */
/*   Updated: 2024/09/30 10:15:02 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			size;
	char			*arr;
	unsigned int	k;

	k = ft_strlen (s);
	if (!s)
		return (NULL);
	if (start >= k)
		return ((char *)ft_calloc(1, 1));
	size = k - start;
	if (len < size)
		arr = (char *)ft_calloc(len + 1, sizeof(char));
	else
		arr = (char *)ft_calloc(size + 1, sizeof(char));
	if (arr != NULL)
	{
		ft_copy(arr, s + start, len);
		return (arr);
	}
	return (NULL);
}
