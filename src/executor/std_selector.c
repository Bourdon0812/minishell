/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_selector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:04:21 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/11 16:19:38 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for control multiple heredocs (<< a << b << c in this case a 
// and b are useless but need to be start)
static int	handle_all_heredocs(t_shell *shell, char **heredocs, int prev_fd)
{
	int		i;
	int		*fd;
	int		last_fd;

	last_fd = prev_fd;
	i = 0;
	while (heredocs[i])
	{
		fd = ft_heredoc(shell, heredocs[i]);
		if (!fd)
			return (-1);
		if (i > 0)
			close(last_fd);
		last_fd = fd[0];
		free(fd);
		i++;
	}
	return (last_fd);
}

///////////////////////////////////////////////////////////////////////////////
// Function for select part 2
static pid_t	good_rep_p2(t_shell *shell, t_cmd *cmd, int in, int out)
{
	if (cmd->heredocs)
	{
		in = handle_all_heredocs(shell, cmd->heredocs, in);
		if (in == -1)
			return (g_signal = EXIT_SIGINT, -1);
	}
	if (g_signal == EXIT_SIGINT)
		return (-1);
	if (shell->cmd[0][0] == '<' && shell->cmd[0][1] == '<')
		return (-1);
	if (is_builtins(cmd->args[0]))
		return (fork_buitins(shell, cmd->args, in, out));
	if (!check_cmd(cmd->args, shell))
		return (-1);
	return (launch_bin(shell, cmd->args, in, out));
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
	if (*prev_fd != STDIN_FILENO)
		close(*prev_fd);
	*prev_fd = fd[0];
	return (pid);
}
