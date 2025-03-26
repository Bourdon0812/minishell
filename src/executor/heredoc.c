/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:13:15 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/26 14:07:31 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function that writes user input to the heredoc until delimiter is found
void	execute_heredoc(char *end, int fd[2])
{
	char	*input;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		input = readline("heredoc> ");
		if (!input)
			break ;
		if (ft_strcmp(input, end) == 0)
		{
			free(input);
			break ;
		}
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
	close(fd[1]);
	exit(0);
}

///////////////////////////////////////////////////////////////////////////////
// Function that handles forking and signal capture for heredoc processing
int	*ft_heredoc(t_shell *shell, char *end)
{
	int		*fd;
	pid_t	pid;
	int		status;

	fd = malloc(sizeof(int) * 2);
	if (!fd || pipe(fd) == -1)
		return (perror("heredoc"), free(fd), NULL);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), free(fd), NULL);
	if (pid == 0)
		execute_heredoc(end, fd);
	close(fd[1]);
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, handle_sigint);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		g_signal = EXIT_SIGINT;
		shell->l_sig = EXIT_SIGINT;
		ft_printf("\n");
	}
	return (fd);
}
