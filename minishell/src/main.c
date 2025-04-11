/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:02:36 by guclemen          #+#    #+#             */
/*   Updated: 2025/04/11 12:10:13 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	should_add_to_history(char *str)
{
	if (!str || !*str)
		return (0);
	if (str[0] == ' ' || (str[0] >= '\t' && str[0] <= '\r'))
		return (0);
	return (ft_not_only_spaces(str));
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)envp;
	while (TRUE)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (should_add_to_history(input))
			add_history(input);
		printf("%s\n", input);
		free(input);
	}
	clear_history();
	return (0);
}
