/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/03 13:08:36 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// rewrite shell for ctrl c
void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

///////////////////////////////////////////////////////////////////////////////
// check if the -c is here
int	check_opt(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strncmp("-c", av[1], 2) == 0)
			return (1);
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// control args (good, wrong, with -c without etc).
int	check_args(int ac, char **av, char **input)
{
	if (ac == 2 || ac > 3)
		return (0);
	if (ac == 3 && !check_opt(ac, av))
		return (0);
	else
	{
		if (!check_opt(ac, av))
			*input = readline(GREEN "minishell> " RESET);
		else
		{
			*input = av[2];
			return (2);
		}
		return (1);
	}
}

///////////////////////////////////////////////////////////////////////////////
// function for the input actions (clean, addHistory, readline, etc)
int	input_act(char **input, char **env)
{
	if (*input == NULL)
		return (0);
	if (ft_strncmp(*input, "exit", 5) == 0)
	{
		free(*input);
		return (0);
	}
	if (**input != '\0')
		add_history(*input);
	free(*input);
	rl_replace_line("", 0);
	*input = readline(GREEN "minishell> " RESET);
	if (*input == NULL)
		return (0);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Main function, start the soft.
int	main(int ac, char **av, char **env)
{
	int		check;
	t_shell	datas;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		datas.running = 1;
		datas.envp = env;
		check = check_args(ac, av, &(datas.input));
		if (check == 2)
			return (0);
		else if (check == 0)
			return (ft_printf("Error wrong args\n"), 1);
		else
		{
			if (!input_act(&(datas.input), env))
				break ;
		}
	}
	return (0);
}
