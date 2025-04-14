/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:16 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/14 10:42:56 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_shell	t_shell;

/* type_utils.c */
int		is_builtins(char *str);
int		ft_iswsp(int c);
int		is_quote(char c);
int		has_pipe(char *input);
int		has_redirection(char *input);

/* env_utils.c */
int		size_env(char **env);
int		copy_env(char ***nenv, char **env, int size, int add);
int		is_valid_varname(char *name);
void	print_env(t_shell *shell);

/* env_utils2.c */
char	*get_env_value(char *env_var, t_shell *shell);
char	*add_shlvl(char *env, int add);
void	free_shell(t_shell *shell, int mode);
void	free_cmd(t_cmd *cmd);
/* struct_utils.c */
t_cmd	*new_cmd(void);

/* lexer_utils.c */
void	clear_lexer(t_shell *shell);
int		parse_argument(char *input, int end);
void	handle_assignment(char *input, int *end);
char	*clean_arg(char *arg, int keep_quotes);
void	ft_free_tab(char **to_clean);
int		check_last_arg(t_shell *shell);

/* echo_utils.c */
int		skip_n_flags(char **args, int *newline_flag);
char	*rm_quotes(char *str);
char	*allocate_result(char *str);
void	expand_env_variable(const char *arg, int *i, int start, t_shell *shell);

/* export_utils.c */
void	update_var(int i, char **env, char *cmd);
void	add_var(t_shell *shell, char *cmd);
char	*get_env_key(char *entry);
int		check_match(char **env, char *key);
int		var_is_in(char **env, char *path);

#endif
