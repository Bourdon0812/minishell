/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/14 13:53:14 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for select the good in / out of the actual cmd
void	good_rep(t_shell *shell, t_cmd *cmd, int in, int out)
{
	int	s_fd[2];

	if (cmd->input_file)
	{
		s_fd[0] = open(cmd->input_file, O_RDONLY);
		if (s_fd[0] == -1)
			return (perror("In error"), (void)0);
	}
	else
		s_fd[0] = in;
	if (cmd->output_file && cmd->append)
	{
		s_fd[1] = open(cmd->output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (s_fd[1] == -1)
			return (perror("Out error"), close(s_fd[0]), (void)0);
	}
	else if (cmd->output_file && !cmd->append)
	{
		s_fd[1] = open(cmd->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (s_fd[1] == -1)
			return (perror("Out error"), close(s_fd[0]), (void)0);
	}
	else
		s_fd[1] = out;
	launch_bin(shell, cmd->args, s_fd[0], s_fd[1]);
}

///////////////////////////////////////////////////////////////////////////////
// Function for open a pip and save him before good_rep function
void	good_with_pip(t_shell *shell, t_cmd *cmd, int *prev_fd, int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	good_rep(shell, cmd, *prev_fd, fd[1]);
	close(fd[1]);
	*prev_fd = fd[0];
}

///////////////////////////////////////////////////////////////////////////////
// Function for complexe command
void	complex_command(t_shell *shell, t_cmd *cmd)
{
	int	fd[2];
	int	prev_fd;

	prev_fd = 0;
	while (cmd)
	{
		if (check_cmd(cmd->args, shell->envp) == 0)
			ft_printf("%s : command not found\n", cmd->args[0]);
		else
		{
			if (cmd->next)
				good_with_pip(shell, cmd, &prev_fd, fd);
			else
				good_rep(shell, cmd, prev_fd, STDOUT_FILENO);
		}
		cmd = cmd->next;
	}
	if (prev_fd != 0)
		close(prev_fd);
}

///////////////////////////////////////////////////////////////////////////////
// Function for the single command without >>, <, | 
void	simple_command(t_shell *shell)
{
	if (is_builtins(shell->cmd[0]))
		exe_builtins(shell);
	else
	{
		if (check_cmd(shell->cmd, shell->envp) == 0)
			ft_printf("%s : command not found\n", shell->cmd[0]);
		else
			launch_bin(shell, shell->cmd, STDIN_FILENO, STDOUT_FILENO);
	}
}
