/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:13:15 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/21 17:05:01 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	event(void)
{
	return (1);
}

void	handle_sig2(int sig)
{
	rl_replace_line("", 0);
	rl_redisplay();
	rl_done = 1;
	g_signal = 130;
}

///////////////////////////////////////////////////////////////////////////////
// Function for start the heredoc (write session).
void	execute_heredoc(t_shell *shell, char **input, char *end, int fd[2])
{
	rl_event_hook = event;
	signal(SIGINT, handle_sig2);
	while (1)
	{
		if (g_signal == 130)
			return (close(fd[1]), shell->l_sig = 130, (void)0);
		*input = readline("heredoc> ");
		if (!(*input) || g_signal == 130)
		{
			free(*input);
			close(fd[1]);
			return ;
		}
		if (ft_strcmp(*input, end) == 0)
		{
			free(*input);
			close(fd[1]);
			return ;
		}
		write(fd[1], *input, strlen(*input));
		write(fd[1], "\n", 1);
		free(*input);
	}
}

///////////////////////////////////////////////////////////////////////////////
// Function that open a textfield that ended by writing "end" and send the 
// result to the actual cmd.
int	*ft_heredoc(t_shell *shell, char *end)
{
	char	*input;
	int		*fd;

	fd = malloc(sizeof(int) * 2);
	if (!fd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe");
		free(fd);
		exit(EXIT_FAILURE);
	}
	execute_heredoc(shell, &input, end, fd);
	return (fd);
}
