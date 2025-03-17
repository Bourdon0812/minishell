/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:04:09 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/17 14:09:52 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

typedef struct s_shell	t_shell;

/* executor.c */
void	complex_command(t_shell *shell, t_cmd *cmd);
void	simple_command(t_shell *shell);
int		*ft_heredoc(char *end);

#endif
