/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/02/26 20:03:53 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <signal.h>

void	handle_sigint(int sig)
{
	(void)sig;
	rl_on_new_line(); 
	printf("\n" GREEN "minishell> " RESET);
	rl_redisplay();
}

int	check_opt(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strncmp("-c", av[2], ft_strlen(av[2])))
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*input;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		if (!check_opt(ac, av))
			input = readline(GREEN "minishell> " RESET);
		else
			input = av[3];
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (ft_strncmp(input, "exit", 6) == 0)
		{
			free(input);
			break ;
		}
		add_history(input);
		free(input);
	}
	return (0);
}
