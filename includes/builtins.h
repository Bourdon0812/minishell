/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:07 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/20 15:47:20 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_shell	t_shell;

/* builtins.c */
void	exe_builtins(t_shell *shell, char **args);

/* echo.c */
void	exe_echo(t_shell *shell, char **args);

/* cd.c */
void	exe_cd(t_shell *shell, char **args);

/* pwd.c */
void	exe_pwd(t_shell *shell, char **args);

/* export.c */
void	exe_export(t_shell *shell, char **args);

/* unset.c */
void	exe_unset(t_shell *shell, char **args);

/* env.c */
void	exe_env(t_shell *shell, char **args);

/* exit.c */
void	exe_exit(t_shell *shell, char **args);

#endif
