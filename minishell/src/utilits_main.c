/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:46:09 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/15 18:14:09 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_build_shell(t_shell *shell, char **envp)
{
	shell->env = alloc_env(count_env(envp));
	copy_env_skip(envp, shell->env, NULL, NULL);
	shell->input = NULL;
	shell->tokens = NULL;
	shell->cmds = NULL;
}

void	ft_clean_shell(t_shell *shell)
{
	free_input_token_cmd(shell->input, shell->tokens, shell->cmds);
	shell->input = NULL;
	shell->tokens = NULL;
	shell->cmds = NULL;
}
