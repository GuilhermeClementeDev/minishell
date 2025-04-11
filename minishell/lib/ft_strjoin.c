/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:48:12 by guclemen          #+#    #+#             */
/*   Updated: 2024/09/30 09:48:15 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*arr;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	arr = (char *)ft_calloc(size, sizeof (char));
	if (arr != NULL)
	{
		ft_strlcat(arr, s1, ft_strlen(s1) + 1);
		ft_strlcat(arr, s2, size);
		return (arr);
	}
	return (NULL);
}
