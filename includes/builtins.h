/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:07 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/05 15:47:41 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct s_shell	t_shell;

/* builtins.c */
void	exe_builtins(t_shell *shell);

/* echo.c */
void	exe_echo(t_shell *shell);

/* cd.c */
void	exe_cd(t_shell *shell);

/* pwd.c */
void	exe_pwd(t_shell *shell);

/* export.c */
void	exe_export(t_shell *shell);

/* unset.c */
void	exe_unset(t_shell *shell);

/* env.c */
void	exe_env(t_shell *shell);

/* exit.c */
void	exe_exit(t_shell *shell);

#endif
