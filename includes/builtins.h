/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:07 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/07 09:44:41 by yseguin          ###   ########.fr       */
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

/* cd.c */
int		exe_cd(t_shell *shell, char **args);

/* pwd.c */
int		exe_pwd(t_shell *shell, char **args);

/* export.c */
int		exe_export(t_shell *shell, char **args);

/* unset.c */
int		exe_unset(t_shell *shell, char **args);

/* env.c */
int		exe_env(t_shell *shell, char **args);

/* exit.c */
void	exe_exit(char **args);

#endif
