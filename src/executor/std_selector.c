/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_selector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:04:21 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/01 14:34:49 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for select part 2
pid_t	good_rep_p2(t_shell *shell, t_cmd *cmd, int in, int out)
{
	int	*fd;

	if (cmd->heredoc != NULL)
	{
		fd = ft_heredoc(shell, cmd->heredoc);
		in = fd[0];
	}
	if (g_signal != EXIT_SIGINT)
	{
		if (is_builtins(cmd->args[0]))
			fork_buitins(shell, cmd->args, in, out);
		else
		{
			if (check_cmd(cmd->args, shell) == 0)
				return (-1);
			else
				return (launch_bin(shell, cmd->args, in, out));
		}
	}
	return (-1);
}

///////////////////////////////////////////////////////////////////////////////
// Function for select the good in / out of the actual cmd
pid_t	good_rep(t_shell *shell, t_cmd *cmd, int in, int out)
{
	int	s_fd[2];

	if (cmd->input_file)
	{
		s_fd[0] = open(cmd->input_file, O_RDONLY);
		if (s_fd[0] == -1)
			return (perror("Minishell :"), -1);
	}
	else
		s_fd[0] = in;
	if (cmd->output_file && cmd->append)
	{
		s_fd[1] = open(cmd->output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (s_fd[1] == -1)
			return (perror("Out error"), close(s_fd[0]), -1);
	}
	else if (cmd->output_file && !cmd->append)
	{
		s_fd[1] = open(cmd->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (s_fd[1] == -1)
			return (perror("Out error"), close(s_fd[0]), -1);
	}
	else
		s_fd[1] = out;
	return (good_rep_p2(shell, cmd, s_fd[0], s_fd[1]));
}

///////////////////////////////////////////////////////////////////////////////
// Function for open a pip and save him before good_rep function
pid_t	good_with_pip(t_shell *shell, t_cmd *cmd, int *prev_fd, int fd[2])
{
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
		return (-1);
	}
	pid = good_rep(shell, cmd, *prev_fd, fd[1]);
	close(fd[1]);
	*prev_fd = fd[0];
	return (pid);
}
