/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:02:48 by guclemen          #+#    #+#             */
/*   Updated: 2025/05/22 18:30:12 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <sys/wait.h>

# define TRUE 1
# define FALSE 0

# define T_WORD 1
# define T_PIPE 2
# define T_RED_IN 3
# define T_RED_OUT 4
# define T_APPEND 5
# define T_HEREDOC 6

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_redirect
{
	int					type;
	char				*filename;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_cmd
{
	char			**args;
	t_redirect		*redirects;
	int				fd_in;
	int				fd_out;
	int				redirect_error;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char		*input;
	t_token		*tokens;
	t_cmd		*cmds;
	char		**env;
}	t_shell;

//main
int			ft_not_only_spaces(char *str);
void		free_input_token_cmd(char *input, t_cmd *cmd_list);

//utilits_main
void		ft_build_shell(t_shell *shell, char **envp);
void		ft_clean_shell(t_shell *shell);
int			is_space_or_invalid(char *input);
t_token		*list_token(char *input);
void		free_input_token_cmd(char *input, t_cmd *cmd_list);

//verify_input.c
int			verify_quotes(const char *str);
int			verify_redirects(const char *str);
int			check_syntax_error(const char *str);

//verify_input_utils.c
int			inside_quotes(const char *str, int i);
int			is_delimiter(char c);

int			is_double_operator(const char *str, int i);
int			is_pipe_space_pipe(const char *str, int *i);

//lexer.c
t_token		*lexer(const char *input);
t_token		*create_token(int type, char *value);
void		create_and_add_token(t_token **head, int type, char *value);

//lexer_utils.c
void		get_word(t_token **head, const char *input, int *i);
void		clean_tokens(t_token *head);

//lexer_tokens.c
int			is_append_or_output(t_token **head, const char *input, int *i);
int			is_heredoc_or_input(t_token **head, const char *input, int *i);
int			is_pipe_token(t_token **head, const char *input, int *i);
void		process_token(t_token **head, const char *input, int *i);

//parser.c
t_cmd		*parse_tokens(t_token *token);

//parser_utils.c
int			handle_redirect(t_token **token, t_redirect **redirects);
int			is_redirect_type(int type);

//free_elements.c
void		free_token_list(t_token *head);
void		free_redirects(t_redirect *redirects);
void		free_commands(t_cmd *cmds);

//var_expansion.c
void		expand_variables_in_token(t_token *token);
char		*expand_variable(char *input, int *index);

//var_expansion_utils.c
int			quoted_part(char *input, int *i, char **expanded_str);
int			var_expansion(char *input, int *i, char **expanded_str);
int			handle_normal_char(char *input, int *i, char **expand_str);
char		*initialize_expanded_str(void);

//var_expansion_utils2.c
void		expand_variables_in_str(char **str, char *input);
int			quotes_or_expansion(char **exp_str, char *input, int *i);

//prints.c
void		print_tokens(t_token **head);
void		print_cmds(t_cmd **cmd);

//prints_utils.c
const char	*token_type_to_str(int type);
const char	*redir_type_to_str(int type);
//utilits
int			ft_not_only_spaces(char *str);

//utilits_env
char		*get_env_value(char **envp, char *key);
int			count_env(char **env);
char		**alloc_env(int entry_count);
void		copy_env_skip(char **old_env, char **new_env, \
char *skip, char *new_var);
void		ft_new_env_pwds(char **envp);

//utilits_export
int			is_valid_export(char *str);
char		*ft_no_spaces(char *str);
int			ft_change_value(char **env, char *new_var);

//error
void		ft_error(char *str, int n);
void		free_env(char **env);

//builtins1
void		ft_echo(char **str);
void		ft_pwd(void);
void		ft_env(char **envp);
void		ft_cd(char **str, char **envp);
void		ft_exit(char **args);

//builtins2
char		**ft_export(char **env, char *new_var);
char		**ft_unset(char **env, char *to_remove);

//pipes.c
int			setup_pipes(t_cmd *cmd_list);

//redirects
void		process_heredocs(t_cmd *cmd_list);
int			prepare_execution(t_cmd *cmd_list);
int			apply_redirects_to_all(t_cmd *cmd_list);

//redirects_utils.c
void		change_cmd_fd(t_cmd *cmd, t_redirect *redir, int fd);
int			open_fd_redir(t_redirect *redir, int *fd);
void		verify_fd_cmd(t_cmd *cmd, t_redirect *r, int fd, int *error);

//heredoc.c
void		process_heredocs(t_cmd *cmd_list);

//heredoc_utils.c
char		*create_heredoc_file(char *delimiter);

//executor
void		execute_pipeline(t_shell *shell);
void		close_cmd_fds(t_cmd *cmd_list);

#endif
