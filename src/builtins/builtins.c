/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:41:11 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/11 15:17:41 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for fork builtin if needed (with pip)
pid_t	fork_buitins(t_shell *shell, char **cmd, int in, int out)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_printf("Error\n"), -1);
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		exe_builtins(shell, cmd);
		shell->l_sig = g_signal;
		g_signal = NEUTRAL_SIGINT;
		exit(shell->l_sig);
	}
	return (pid);
}

///////////////////////////////////////////////////////////////////////////////
// Function for exec a builtIn in main process
void	exe_builtins(t_shell *shell, char **args)
{
	int	val;

	val = NEUTRAL_SIGINT;
	if (ft_strcmp(args[0], "echo") == 0)
		val = exe_echo(shell, args);
	else if (ft_strcmp(args[0], "cd") == 0)
		val = exe_cd(shell, args);
	else if (ft_strcmp(args[0], "pwd") == 0)
		val = exe_pwd(args);
	else if (ft_strcmp(args[0], "export") == 0)
		val = exe_export(shell, args);
	else if (ft_strcmp(args[0], "env") == 0)
		val = exe_env(shell, args);
	else if (ft_strcmp(args[0], "exit") == 0)
		exe_exit(shell, args);
	else if (ft_strcmp(args[0], "unset") == 0)
		val = exe_unset(shell, args);
	g_signal = val;
}
