/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:02:36 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/15 23:22:16 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*list_token(char *input)
{
	t_token	*token_list;

	token_list = lexer(input);
	expand_variables_in_token(token_list);
	clean_tokens(token_list);
	return (token_list);
}

void	free_input_token_cmd(char *input, t_token *token_list, t_cmd *cmd_list)
{
	free(input);
	free_token_list(token_list);
	free_commands(cmd_list);
}

int	is_space_or_invalid(char *input)
{
	if (!ft_not_only_spaces(input))
	{
		free(input);
		input = NULL;
		return (1);
	}
	if (check_syntax_error(input))
	{
		free(input);
		input = NULL;
		return (1);
	}
	return (0);
}

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
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	(void)argc;
	(void)argv;
	ft_build_shell(shell, envp);
	while (TRUE)
	{
		shell->input = readline("minishell> ");
		if (!shell->input)
			break ;
		if (is_space_or_invalid(shell->input))
			continue ;
		shell->tokens = list_token(shell->input);
		shell->cmds = parse_tokens(shell->tokens);
		if (should_add_to_history(shell->input))
			add_history(shell->input);
		ft_executer(shell);
		ft_clean_shell(shell);
	}
	free_env(shell->env);
	free(shell);
	clear_history();
	return (0);
}
