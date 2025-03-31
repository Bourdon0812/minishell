/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/31 17:09:24 by yseguin          ###   ########.fr       */
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
			exe_builtins(shell, cmd->args);
		else
		{
			if (check_cmd(cmd->args, shell->envp) == 0)
				return(ft_printf("%s : command not found\n", cmd->args[0]), -1);
			else
				return launch_bin(shell, cmd->args, in, out);
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
	return good_rep_p2(shell, cmd, s_fd[0], s_fd[1]);
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

///////////////////////////////////////////////////////////////////////////////
// Function for complexe command
void	complex_command(t_shell *shell, t_cmd *cmd)
{
	pid_t	pids[1024];
	pid_t	last_pid;
	int		fd[2];
	int		prev_fd;
	int		i;

	prev_fd = 0;
	i = 0;
	while (cmd)
	{
		if (g_signal == EXIT_SIGINT)
			return (g_signal = NEUTRAL_SIGINT, (void)0);
		if (check_cmd(cmd->args, shell->envp) == 0)
			ft_printf("%s : command not found\n", cmd->args[0]);
		else
		{
			if (cmd->next)
				pids[i] = good_with_pip(shell, cmd, &prev_fd, fd);
			else
				pids[i] = good_rep(shell, cmd, prev_fd, STDOUT_FILENO);
			last_pid = pids[i];
			i++;
		}
		cmd = cmd->next;
	}
	if (prev_fd != 0)
		close(prev_fd);
	for (int j = 0; j < i; j++)
		wait_all(pids[j], last_pid, shell);
}

///////////////////////////////////////////////////////////////////////////////
// Function for the single command without >>, <, | 
void	simple_command(t_shell *shell)
{
	pid_t pid;
	int status;

	if (is_builtins(shell->cmd[0]))
		exe_builtins(shell, shell->cmd);
	else
	{
		if (check_cmd(shell->cmd, shell->envp) == 0)
			ft_printf("%s : command not found\n", shell->cmd[0]);
		else
		{
			pid = launch_bin(shell, shell->cmd, STDIN_FILENO, STDOUT_FILENO);
			wait_all(pid, pid, shell);
		}
	}
}
