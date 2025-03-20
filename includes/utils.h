/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:16 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/20 14:46:28 by ilbonnev         ###   ########.fr       */
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

/* struct_utils.c */
t_cmd	*new_cmd(void);

/* lexer_utils.c */
void	clear_lexer(t_shell *shell);

#endif
