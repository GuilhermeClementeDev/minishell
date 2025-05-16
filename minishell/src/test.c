/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:10:36 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/15 18:19:17 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include "minishell.h"

void	execute_command(t_cmd *cmd, char **envp)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (strcmp(cmd->args[0], "cd") == 0)
		ft_cd(cmd->args, envp);
	else if (strcmp(cmd->args[0], "pwd") == 0)
		ft_pwd();
	else if (strcmp(cmd->args[0], "env") == 0)
		ft_env(envp);
	else
		printf("fe");
}
