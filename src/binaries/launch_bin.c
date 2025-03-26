/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:36:54 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/26 14:12:09 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// function for obtain the path of a binaries
char	*search_path(char *cmd, char **env)
{
	int		fd[2];
	pid_t	pid;
	char	*result;

	if (pipe(fd) == -1)
		return (perror("pipe"), NULL);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), NULL);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd[1], STDERR_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/which", (char *[]){"which", cmd, NULL}, env);
		exit(1);
	}
	close(fd[1]);
	result = get_next_line(fd[0]);
	free(get_next_line(fd[0]));
	close(fd[0]);
	waitpid(pid, NULL, 0);
	return (result);
}

///////////////////////////////////////////////////////////////////////////////
// function for execute the cmd in a selected fd from a selected fd
void	binaries_in_out(t_shell *shell, char **cmd, int infd, int outfd)
{
	char	*cmd_path;

	cmd_path = search_path(cmd[0], shell->envp);
	cmd_path[ft_strlen(cmd_path) - 1] = '\0';
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	execve(cmd_path, cmd, shell->envp);
	free(cmd_path);
	exit(1);
}

///////////////////////////////////////////////////////////////////////////////
// function for execute a cmd in his own process and wait it.
void	launch_bin(t_shell *shell, char **cmd, int in, int out)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_printf("Error\n"), (void)0);
	if (pid == 0)
	{
		binaries_in_out(shell, cmd, in, out);
		exit(1);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		signal(SIGINT, handle_sigint);
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
// function for check if the cmd is usable or not
int	check_cmd(char **args, char **env)
{
	char	*path;
	int		is_valid;

	path = search_path(args[0], env);
	if (!path)
		return (0);
	is_valid = 1;
	if (ft_strncmp(path, "which: no ", 10) == 0)
		is_valid = 0;
	free(path);
	return (is_valid);
}
