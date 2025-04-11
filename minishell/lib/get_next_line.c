/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:54 by guclemen          #+#    #+#             */
/*   Updated: 2024/11/04 13:33:56 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_newstr(char *s)
{
	char	*str;
	int		size;

	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s, size + 1);
	str[size + 1] = '\0';
	s = ft_free(s);
	return (str);
}

static char	*extract_l(char *s)
{
	int		size;
	char	*str;
	int		full_size;

	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	if (s[size] == '\0')
		return (NULL);
	full_size = (ft_strlen(s) - (size));
	str = (char *)malloc(sizeof(char) * full_size);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, &s[size + 1], full_size);
	return (str);
}

static int	ft_verify(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_f(int fd, char *tmp, char *cont)
{
	int		rz;

	rz = 1;
	while (rz != 0)
	{
		rz = read(fd, tmp, BUFFER_SIZE);
		if (rz == -1)
			return (NULL);
		if (rz == 0)
			break ;
		tmp[rz] = '\0';
		if (!cont)
			cont = ft_strdup_gnl("");
		cont = ft_join_gnl(cont, tmp);
		if (ft_verify(tmp))
			break ;
	}
	return (cont);
}

char	*get_next_line(int fd)
{
	static char	*cont;
	char		*string;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	string = read_f(fd, tmp, cont);
	tmp = ft_free(tmp);
	if (!string)
		return (NULL);
	cont = extract_l(string);
	if (cont && *cont != '\0')
		string = ft_newstr(string);
	if (cont && *cont == '\0')
		cont = ft_free(cont);
	return (string);
}
