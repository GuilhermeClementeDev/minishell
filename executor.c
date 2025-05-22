/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@example.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:00:00 by assistant          #+#    #+#             */
/*   Updated: 2025/05/15 11:00:00 by assistant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/src/minishell.h"

#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

// ---- Builtins que você forneceu (protótipos) ----

// ---- Helpers ----

// Builtins rodados no processo pai (mudam estado do shell)
static int exec_builtin_parent(t_cmd *cmd, char **envp)
{
    if (!cmd->args || !cmd->args[0])
        return (0);
    if (strcmp(cmd->args[0], "cd") == 0)
    {
        ft_cd(cmd->args, envp);
        return (1);
    }
    if (strcmp(cmd->args[0], "exit") == 0)
    {
        ft_exit(cmd->args);
        return (1);
    }
    if (strcmp(cmd->args[0], "export") == 0)
    {
        envp = ft_export(envp, cmd->args[1]);
        return (1);
    }
    if (strcmp(cmd->args[0], "unset") == 0)
    {
        envp = ft_unset(envp, cmd->args[1]);
        return (1);
    }
    return (0);
}

// Builtins rodados no filho (eco, pwd, env)
static int	exec_builtin_child(t_cmd *cmd, char **envp)
{
	(void)envp;
	if (!cmd->args || !cmd->args[0])
		return (0);
	if (strcmp(cmd->args[0], "echo") == 0)
	{
		ft_echo(cmd->args);
		return (1);
	}
	else if (strcmp(cmd->args[0], "pwd") == 0)
	{
		ft_pwd();
		return (1);
	}
	else if (strcmp(cmd->args[0], "env") == 0)
	{
		ft_env(envp);
		return (1);
	}
	return (0);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Procura executável no PATH, retorna malloc com caminho ou NULL
static char	*find_executable(char *cmd_name, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	if (strchr(cmd_name, '/'))
		return (strdup(cmd_name));

	path_env = NULL;
	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_env)
		return (NULL);

	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);

	i = 0;
	while (paths[i])
	{
		full_path = malloc(strlen(paths[i]) + 1 + strlen(cmd_name) + 1);
		if (!full_path)
			break ;
		strcpy(full_path, paths[i]);
		strcat(full_path, "/");
		strcat(full_path, cmd_name);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

// Fecha FDs abertos dos comandos (exceto std)
void close_cmd_fds(t_cmd *cmd_list)
{
    t_cmd *cmd;

    cmd = cmd_list;
    while (cmd)
    {
        if (cmd->fd_in != STDIN_FILENO)
            close(cmd->fd_in);
        if (cmd->fd_out != STDOUT_FILENO)
            close(cmd->fd_out);
        cmd = cmd->next;
    }
}


// Executa comando externo no filho
static void exec_external_cmd(t_cmd *cmd, char **envp)
{
    char *exec_path;

    exec_path = find_executable(cmd->args[0], envp);
    if (!exec_path)
    {
        ft_putstr_fd(cmd->args[0], 2);
        ft_putstr_fd(": command not found\n", 2);
        free(exec_path); // adicionar esta linha!
        exit(127);
    }
    execve(exec_path, cmd->args, envp);

    // Se execve falhar:
    perror("execve");
    free(exec_path);
    free_commands(cmd); // ← liberar antes de exit
    exit(EXIT_FAILURE);
}

// Executa um comando no filho
static void execute_single_command(t_shell *shell, t_cmd *cmd, char ***envp)
{
    if (cmd->redirect_error)
        exit(1); // Se houver erro no redirecionamento, sai

    // Redireciona a entrada e saída se necessário
    if (cmd->fd_in != STDIN_FILENO)
    {
        dup2(cmd->fd_in, STDIN_FILENO);
        close(cmd->fd_in);
    }
    if (cmd->fd_out != STDOUT_FILENO)
    {
        dup2(cmd->fd_out, STDOUT_FILENO);
        close(cmd->fd_out);
    }

    if (exec_builtin_child(cmd, *envp))
    {
        ft_clean_shell(shell);
        free_env(*envp);
        free(shell);
    	exit(0);
    }

    exec_external_cmd(cmd, *envp);
}

// Executa pipeline de comandos
void execute_pipeline(t_shell *shell)
{
    t_cmd	*cmd;
    pid_t	pid;
    int		status;

    cmd = shell->cmds;
    while (cmd)
    {
        if (!cmd->next && exec_builtin_parent(cmd, shell->env))
        {
            cmd = cmd->next;
            continue ;
        }

        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) // Filho
            execute_single_command(shell,cmd, &shell->env);

        if (cmd->fd_in != STDIN_FILENO)
            close(cmd->fd_in);
        if (cmd->fd_out != STDOUT_FILENO)
            close(cmd->fd_out);

        cmd = cmd->next;
    }
    while (wait(&status) > 0)
        ;
}
