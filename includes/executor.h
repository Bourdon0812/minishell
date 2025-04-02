/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:09 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/01 14:51:49 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_shell	t_shell;

/* executor.c */
void	complex_command(t_shell *shell, t_cmd *cmd);
void	simple_command(t_shell *shell);

/* heredoc */
int		*ft_heredoc(t_shell *shell, char *end);

/* std selector*/
pid_t	good_with_pip(t_shell *shell, t_cmd *cmd, int *prev_fd, int fd[2]);
pid_t	good_rep(t_shell *shell, t_cmd *cmd, int in, int out);
#endif
