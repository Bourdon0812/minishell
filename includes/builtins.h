/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:07 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/02/21 02:07:58 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

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
