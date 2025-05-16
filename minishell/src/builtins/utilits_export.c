/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:06:49 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/15 18:24:54 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_export(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '=')
		i++;
	if (i == 0 || str[i] != '=')
		return (0);
	if (str[i - 1] == ' ')
		return (0);
	return (1);
}

char	*ft_no_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (ft_strdup(str));
}

int	ft_change_value(char **env, char *new_var)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] == new_var[j] && new_var[j] != '=' && env[i][j] != '=')
			j++;
		if (new_var[j] == '=' && env[i][j] == '=')
		{
			free(env[i]);
			env[i] = ft_no_spaces(new_var);
			return (1);
		}
		i++;
	}
	return (0);
}
