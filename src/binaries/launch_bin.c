/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:36:54 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/31 18:30:38 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// function for obtain the path of a binaries
char	*search_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(allpath);
	ft_free_tab(s_cmd);
	return (NULL);
}

///////////////////////////////////////////////////////////////////////////////
// function for execute the cmd in a selected fd from a selected fd
void	binaries_in_out(char **envp, char **cmd, int infd, int outfd)
{
	char	*cmd_path;

	cmd_path = search_path(cmd[0], envp);
	cmd_path[ft_strlen(cmd_path)] = '\0';
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	execve(cmd_path, cmd, envp);
	free(cmd_path);
	if (infd != STDIN_FILENO)
		close(infd);
	if (outfd != STDOUT_FILENO)
		close(outfd);
	exit(1);
}

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
		binaries_in_out(shell->envp, cmd, in, out);
		exit(1);
	}
	return pid;
}

///////////////////////////////////////////////////////////////////////////////
// function for check if the cmd is usable or not
int	check_cmd(char **args, char **env)
{
	char	*path;


	path = search_path(args[0], env);
	if (!path)
		return (0);
	free(path);
	return (1);
}
