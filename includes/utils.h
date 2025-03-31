/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:16 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/31 18:30:21 by yseguin          ###   ########.fr       */
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
int		copy_env(char ***nenv, char **env, int size);
int		is_valid_varname(char *name);
void	print_env(t_shell *shell);
char	*get_env_value(char *env_var);
char	*my_getenv(char *name, char **env);

/* struct_utils.c */
t_cmd	*new_cmd(void);

/* lexer_utils.c */
void	clear_lexer(t_shell *shell);
int		parse_argument(char *input, int end);
void	handle_assignment(char *input, int *end);
char	*clean_arg(char *arg, int keep_quotes);
void	ft_free_tab(char **to_clean);
#endif
