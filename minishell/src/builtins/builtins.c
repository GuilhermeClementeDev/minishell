/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:56:02 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/15 22:34:01 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **str)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (str[i] && ft_strncmp(str[i], "-n", ft_strlen(str[i])) == 0)
	{
		flag = 1;
		i++;
	}
	while (str[i])
	{
		printf("%s", str[i]);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
}

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		ft_error("Unable to get pwd", 1);
}

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

void	ft_cd(char **str, char **envp)
{
	const char	*path;

	if (str[1])
		path = str[1];
	else
		path = get_env_value(envp, "HOME");
	if (path)
	{
		if (chdir(path) != 0)
		{
			ft_putstr_fd ("-minishell: cd: ", 2);
			ft_putstr_fd ((char *)path, 2);
			ft_putstr_fd (": No such file or directory\n", 2);
		}
		else
			ft_new_env_pwds(envp);
	}
}

void	ft_exit(char **args)
{
	int	status;

	status = 0;
	if (args[1])
		status = ft_atoi(args[1]);
	printf("exit\n");
	exit(status);
}
/* //echo
int main(void)
{
	// Testes ft_echo
	printf("Teste 1: echo hello world\n");
	ft_echo((char *[]){"echo", "hello", "world", NULL});

	printf("Teste 2: echo -n sem quebra de linha\n");
	ft_echo((char *[]){"echo", "-n", "sem", "quebra", "de", "linha", NULL});

	printf("Teste 3: echo sem argumentos\n");
	ft_echo((char *[]){"echo", NULL});

	printf("Teste 4: echo -n sozinho\n");
	ft_echo((char *[]){"echo", "-n", NULL});

	return 0;
}
*/

/* pwd
int main()
{
	ft_pwd();
}
*/

/* ft_env
int main(int argc, char **argv, char **envp)
{
	// Testa a função ft_env com o envp passado pelo sistema
	(void)argc;
	(void)argv;
	ft_env(envp);

	return 0;
}
*/
/* // cd
int main(int argc, char **argv, char **envp)
{
    if (argc > 1)
        ft_cd(argv, envp);
    else
    {
        char *no_args[] = { "cd", NULL };
        ft_cd(no_args, envp);
    }

    // Agora imprime o diretório atual para você conferir
	ft_pwd();
    return 0;
}*/
