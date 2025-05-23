/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:07 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/14 11:00:55 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_shell	t_shell;

/* fork builtIns for pip*/
pid_t	fork_buitins(t_shell *shell, char **cmd, int in, int out);

/* builtins.c */
void	exe_builtins(t_shell *shell, char **args);

/* echo.c */
int		exe_echo(t_shell *shell, char **args);
void	handle_dollar(const char *arg, int *i, t_shell *shell);

/* cd.c */
int		exe_cd(t_shell *shell, char **args);

/* pwd.c */
int		exe_pwd(char **args);

/* export.c */
int		exe_export(t_shell *shell, char **args);
void	start_exp(int i, t_shell *shell, char **args);
void	handle_invalid_export(char *arg, char *original);
char	*handle_missing_equal(char *arg);

/* unset.c */
int		exe_unset(t_shell *shell, char **args);

/* env.c */
int		exe_env(t_shell *shell, char **args);

/* exit.c */
void	exe_exit(t_shell *shell, char **args);

#endif
