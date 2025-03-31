/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:56:39 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/31 16:08:39 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARIES_H
# define BINARIES_H

/* function */
pid_t	launch_bin(t_shell *shell, char **cmd, int in, int out);
void	wait_all(pid_t pid, pid_t last_pid, t_shell *shell);
int		check_cmd(char **args, char **env);

#endif