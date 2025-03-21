/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:09 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/21 17:02:58 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_shell	t_shell;

/* executor.c */
void	complex_command(t_shell *shell, t_cmd *cmd);
void	simple_command(t_shell *shell);
int		*ft_heredoc(t_shell *shell, char *end);

#endif
