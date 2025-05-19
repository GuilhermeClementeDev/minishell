/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:19:25 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/18 13:06:53 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

	command = shell->cmds->args[0];
	if (!ft_strncmp(command, "cd", 3))
		ft_cd(shell ,shell->cmds->args, shell->env);
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
			/*
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
			*/

			if (!ft_strncmp(command, "echo", 5))
				ft_echo(shell->cmds->args);
			else if (!ft_strncmp(command, "pwd", 4))
				ft_pwd();
			else if (!ft_strncmp(command, "env", 4))
				ft_env(shell->env);
			exit(0);
		}
		else if (pid > 0)
			waitpid(pid, NULL, 0);
		else
			perror("fork");
	}
}
char	*find_cmd_path(t_shell *shell)
{
	char	**paths;
	char	*path_env;
	int		i;

	i = 0;
	path_env = get_env_value(shell->env, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	while (paths[i])
	{
		path_env = ft_strjoin(paths[i], "/");
		path_env = ft_join_gnl(path_env, shell->cmds->args[0]);
		if (access(path_env, X_OK) == 0)
		{
			free_env(paths);
			return (path_env);
		}
		free(path_env);
		i++;
	}
	free_env(paths);
	return (NULL);
}
void	execute_external_func(t_shell *shell)
{
	char	*path;
	pid_t	pid;

	if (ft_strchr(shell->cmds->args[0], '/'))
		path = ft_strdup(shell->cmds->args[0]);
	else
		path = find_cmd_path(shell);
	if (!path)
	{
		ft_putstr_fd("-bash: ", 2);
		ft_putstr_fd(shell->cmds->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		return ;
	}
	pid = fork();
	if (pid == 0)
		execve(path, shell->cmds->args, shell->env);
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		perror("fork");
	free(path);
}

void	ft_executer(t_shell *shell)
{
	if (!shell->cmds || !shell->cmds->args || !shell->cmds->args[0])
		return ;
	if (is_builtin(shell->cmds->args[0]))
		execute_builtin(shell);
	else
		execute_external_func(shell);
}
