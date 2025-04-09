/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/09 16:15:41 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

sig_atomic_t	g_signal = 0;

///////////////////////////////////////////////////////////////////////////////
// check if the -c is here
static int	check_opt(int ac, char **av)
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
static int	check_args(int ac, char **av, char **input)
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
			*input = ft_strdup(av[2]);
			return (2);
		}
		return (1);
	}
}

///////////////////////////////////////////////////////////////////////////////
// function for the input actions (clean, addHistory, readline, etc)
static int	input_act(t_shell *shell)
{
	if (shell->input == NULL)
		return (0);
	if (shell->input[0] != '\0')
		add_history(shell->input);
	rl_replace_line("", 0);
	lexer(shell);
	free_shell(shell, 1);
	return (1);
}

static void end_c(t_shell *shell, int mode)
{
	if (mode)
		lexer(shell);
	free_shell(shell, 0);
}

///////////////////////////////////////////////////////////////////////////////
// Main function, start the soft.
int	main(int ac, char **av, char **env)
{
	int		check;
	t_shell	shell;

	shell = (t_shell){};
	disable_slprint();
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	if (copy_env(&shell.envp, env, (size_env(env) + 1)) == 0)
		return (ft_printf("Error with env\n"), 1);
	while (1)
	{
		g_signal = NEUTRAL_SIGINT;
		check = check_args(ac, av, &(shell.input));
		if (check == 2)
			return (end_c(&shell, 1), 0);
		else if (check == 0)
			return (end_c(&shell, 0), ft_printf("Error wrong args\n"), 1);
		else
		{
			if (!input_act(&shell))
				exe_exit(&shell, (char *[]){"0", NULL});
		}
	}
	return (0);
}
