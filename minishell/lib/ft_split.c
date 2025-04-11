/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:21:35 by guclemen          #+#    #+#             */
/*   Updated: 2024/10/11 14:21:37 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *s, int c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (s[i] == '\0')
		count++;
	if (s[0] != c)
		count++;
	return (count);
}

static int	ft_sizeword(const char *src, int c)
{
	unsigned int	i;

	i = 0;
	while (src[i] != c && src[i])
		i++;
	return (i);
}

static void	ft_allocword(char **ptrs, const char *s, int c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	size;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		size = ft_sizeword(&s[i], c);
		if (!s[i])
		{
			ptrs[k] = NULL;
			break ;
		}
		ptrs[k] = (char *)ft_calloc (size + 1, 1);
		ft_strlcpy(ptrs[k], &s[i], size + 1);
		k++;
		while (s[i] != c && s[i])
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**ptrs;
	unsigned int	words;

	if (!s)
		return (NULL);
	if (!s[0])
	{
		ptrs = ((char **) ft_calloc(1, sizeof(char *)));
		ptrs[0] = NULL;
		return (ptrs);
	}
	words = ft_words (s, c);
	ptrs = (char **)ft_calloc(words, sizeof(char *));
	ft_allocword (ptrs, s, c);
	return (ptrs);
}
