/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:17:20 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/15 23:05:14 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_export(char **env, char *new_var)
{
	int		count;
	char	**new_env;
	char	*no_spaces;

	if (!is_valid_export(new_var))
		return (env);
	if (ft_change_value(env, new_var))
		return (env);
	count = count_env(env) + 1;
	new_env = alloc_env(count);
	if (!new_env)
		return (env);
	no_spaces = ft_no_spaces(new_var);
	copy_env_skip(env, new_env, NULL, no_spaces);
	free(no_spaces);
	free_env(env);
	return (new_env);
}

char	**ft_unset(char **env, char *to_remove)
{
	int		count;
	char	**new_env;

	if (!get_env_value(env, to_remove))
		return (env);
	count = count_env(env) - 1;
	new_env = alloc_env(count);
	if (!new_env)
		return (env);
	copy_env_skip(env, new_env, to_remove, NULL);
	free_env(env);
	return (new_env);
}
/*
int main(void) {
    char *test_env[] = {
        "USER=guest",
        "PATH=/usr/bin:/bin",
        "HOME=/home/guest",
        NULL
    };

    char **env = alloc_env(count_env(test_env));
    for (int i = 0; test_env[i]; i++)
        env[i] = strdup(test_env[i]);

    printf("Original environment (%d entries):\n", count_env(env));
    for (int i = 0; env[i]; i++)
        printf("  [%d] %s\n", i, env[i]);
    printf("\n");

    env = ft_export(env, "   TEST1=hello");
    env = ft_export(env, "TEST2=world");
    env = ft_export(env, "INVALID");
    env = ft_export(env, "=oops");
    env = ft_export(env, "    \tMYVAR=withtabs");
    env = ft_export(env, "SINGLECHAR=A");
    env = ft_export(env, "    KEY=   spacedvalue");
    env = ft_export(env, "MIXED=   content with spaces   ");
    env = ft_export(env, "TEST2=vasco");

    printf("After export tests (%d entries):\n", count_env(env));
    for (int i = 0; env[i]; i++)
        printf("  [%d] %s\n", i, env[i]);
    printf("\n");

    env = ft_unset(env, "PATH");
    env = ft_unset(env, "NONEXISTENT");

    printf("After unset tests (%d entries):\n", count_env(env));
    for (int i = 0; env[i]; i++)
        printf("  [%d] %s\n", i, env[i]);
    printf("\n");

    free_env(env);
    return 0;
}*/
