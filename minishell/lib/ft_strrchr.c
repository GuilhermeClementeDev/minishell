/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:16:28 by guclemen          #+#    #+#             */
/*   Updated: 2024/09/24 14:16:31 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
  printf("%s\n", strrchr("I love CRVG", 'a'));
  printf("%s\n", ft_strrchr("I love CRVG", 'a'));
}
*/
