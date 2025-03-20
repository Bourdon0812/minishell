/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:13:15 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/20 15:03:04 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sig2(int sig)
{
	(void)sig;
	// à compléter
}

///////////////////////////////////////////////////////////////////////////////
// Function for start the heredoc (write session).
void	execute_heredoc(char **input, char *end, int fd[2])
{
	signal(SIGINT, handle_sig2);
	while (1)
	{
		*input = readline("heredoc> ");
		if (!(*input))
		{
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
int	*ft_heredoc(char *end)
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
	execute_heredoc(&input, end, fd);
	return (fd);
}
