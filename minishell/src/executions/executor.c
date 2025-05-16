/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:19:25 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/15 23:54:42 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
int	is_builtin(char *cmd)
{
	int		size;

	size = ft_strlen(cmd);
	if (!ft_strncmp(cmd, "cd", size) || !ft_strncmp(cmd, "pwd", size) || \
	!ft_strncmp(cmd, "exit", size) || !ft_strncmp(cmd, "export", size) || \
	!ft_strncmp(cmd, "unset", size) || !ft_strncmp(cmd, "env", size) || \
	!ft_strncmp(cmd, "echo", size))
		return (1);
	return (0);
}

void	execute_builtin(t_shell *shell)
{
	char	*command;
	pid_t	pid;
	int		status;

	command = shell->cmds->args[0];
	if (!ft_strncmp(command, "cd", 3))
		ft_cd(shell->cmds->args, shell->env);
	else if (!ft_strncmp(command, "exit", 5))
		ft_exit(shell->cmds->args);
	else if (!ft_strncmp(command, "export", 7))
		shell->env = ft_export(shell->env, shell->cmds->args[1]);
	else if (!ft_strncmp(command, "unset", 6))
		shell->env = ft_unset(shell->env, shell->cmds->args[1]);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			// Aqui você pode tratar os redirecionamentos se necessário

			if (cmd->fd_out != 1)
			{
				dup2(cmd->fd_out, 1);
				close(cmd->fd_out);
			}
			if (cmd->fd_in != 0)
			{
				dup2(cmd->fd_in, 0);
				close(cmd->fd_in);
			}


			if (!ft_strncmp(command, "echo", 5))
				ft_echo(shell->cmds->args);
			else if (!ft_strncmp(command, "pwd", 4))
				ft_pwd();
			else if (!ft_strncmp(command, "env", 4))
				ft_env(shell->env);
			exit(0);
		}
		else if (pid > 0)
			waitpid(pid, &status, 0);
		else
			perror("fork");
	}
}


void	ft_executer(t_shell *shell)
{
	if (!shell->cmds || !shell->cmds->args || !shell->cmds->args[0])
		return ;
	if (is_builtin(shell->cmds->args[0]))
		execute_builtin(shell);
	else
		printf("Executável externo ainda não \
		implementado: %s\n", shell->cmds->args[0]);
}
*/
