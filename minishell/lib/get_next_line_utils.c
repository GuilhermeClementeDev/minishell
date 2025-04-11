/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:06 by guclemen          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:07 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *tmp)
{
	free(tmp);
	tmp = NULL;
	return (tmp);
}

char	*ft_strdup_gnl(char *s)
{
	int				size;
	char			*ptr;

	size = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[size] = '\0';
	size--;
	while (size >= 0)
	{
		ptr[size] = s[size];
		size--;
	}
	return (ptr);
}

char	*ft_join_gnl(char *s1, char *s2)
{
	unsigned int	size1;
	unsigned int	size2;
	char			*arr;

	if (!s1)
	{
		s1 = ft_strdup_gnl("");
		if (!s1)
			return (NULL);
	}
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (arr != NULL)
	{
		arr = (char *)ft_memcpy(arr, s1, size1);
		ft_memcpy(arr + size1, s2, size2);
		arr[size1 + size2] = '\0';
		s1 = ft_free(s1);
		return (arr);
	}
	return (NULL);
}
