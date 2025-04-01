/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:41:11 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/01 14:32:18 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		exit(1);
	}
	return (pid);
}

void	exe_builtins(t_shell *shell, char **args)
{
	if (ft_strcmp(shell->cmd[0], "echo") == 0)
		exe_echo(shell, args);
	else if (ft_strcmp(shell->cmd[0], "cd") == 0)
		exe_cd(shell, args);
	else if (ft_strcmp(shell->cmd[0], "pwd") == 0)
		exe_pwd(shell, args);
	else if (ft_strcmp(shell->cmd[0], "export") == 0)
		exe_export(shell, args);
	else if (ft_strcmp(shell->cmd[0], "env") == 0)
		exe_env(shell, args);
	else if (ft_strcmp(shell->cmd[0], "exit") == 0)
		exe_exit(shell, args);
	else if (ft_strcmp(shell->cmd[0], "unset") == 0)
		exe_unset(shell, args);
}
