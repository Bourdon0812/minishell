/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/27 14:52:51 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

sig_atomic_t	g_signal = 0;

///////////////////////////////////////////////////////////////////////////////
// rewrite shell for ctrl c
void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	//rl_replace_line("", 0);
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
			*input = readline(GREEN "Minishell> " RESET);
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
int	input_act(t_shell *shell)
{
	if (shell->input == NULL)
		return (0);
	if (ft_strncmp(shell->input, "exit", 5) == 0)
	{
		free(shell->input);
		return (0);
	}
	if (shell->input[0] != '\0')
		add_history(shell->input);
	//rl_replace_line("", 0);
	if (shell->input == NULL)
		return (0);
	lexer(shell);
	free(shell->input);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Main function, start the soft.
int	main(int ac, char **av, char **env)
{
	int		check;
	t_shell	shell;

	signal(SIGINT, handle_sigint);
	if (copy_env(&(shell.envp), env, (size_env(env) + 1)) == 0)
		return (ft_printf("Error with env\n"), 1);
	while (1)
	{
		shell.l_sig = NEUTRAL_SIGINT;
		g_signal = NEUTRAL_SIGINT;
		check = check_args(ac, av, &(shell.input));
		if (check == 2)
			return (lexer(&shell), 0);
		else if (check == 0)
			return (ft_printf("Error wrong args\n"), 1);
		else
		{
			if (!input_act(&shell))
				break ;
		}
	}
	return (0);
}
