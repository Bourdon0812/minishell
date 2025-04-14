/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:36:54 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/14 10:12:12 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// function for execute the cmd in a selected fd from a selected fd
static void	binaries_in_out(t_shell *shell, char **cmd, int infd, int outfd)
{
	char	*cmd_path;
	int		fd;
	int		i;

	i = 0;
	cmd_path = search_path(cmd[0], shell, i);
	cmd_path[ft_strlen(cmd_path)] = '\0';
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	if (infd != STDIN_FILENO)
		close(infd);
	if (outfd != STDOUT_FILENO)
		close(outfd);
	fd = 0;
	while (fd < 1024)
	{
		if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO
			&& fd != infd && fd != outfd)
			close(fd);
		fd++;
	}
	execve(cmd_path, cmd, shell->envp);
	free(cmd_path);
	exit(1);
}

///////////////////////////////////////////////////////////////////////////////
// Function for wait all pid
void	wait_all(pid_t pid, pid_t last_pid, t_shell *shell)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, handle_sigint);
	if (pid == last_pid)
	{
		if (WIFEXITED(status))
			shell->l_sig = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			shell->l_sig = 128 + WTERMSIG(status);
			ft_printf("\n");
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
// function for execute a cmd in his own process and wait it.
pid_t	launch_bin(t_shell *shell, char **cmd, int in, int out)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_printf("Error\n"), -1);
	if (pid == 0)
	{
		binaries_in_out(shell, cmd, in, out);
		exit(1);
	}
	return (pid);
}

///////////////////////////////////////////////////////////////////////////////
// function for check if the cmd is usable or not
int	check_cmd(char **args, t_shell *shell)
{
	char	*path;
	int		i;

	i = 0;
	path = search_path(args[0], shell, i);
	if (!path)
	{
		ft_printf("Minishell: %s: command not found\n", args[0]);
		shell->l_sig = 1;
		return (0);
	}
	free(path);
	return (1);
}
