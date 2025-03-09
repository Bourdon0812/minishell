/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/09 12:36:27 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for complexe command
void	complex_command(t_shell *shell)
{
	return ;
}

///////////////////////////////////////////////////////////////////////////////
// Function for the single command without >>, <, | 
void	simple_command(t_shell *shell)
{
	int	status;
	int	pid;

	if (is_builtins(shell->cmd[0]))
		exe_builtins(shell);
	else
	{
		pid = fork();
		if (pid == -1)
			ft_printf("Error\n");
		if (pid == 0)
		{
			binaries_in_out(shell, STDIN_FILENO, STDOUT_FILENO);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
	}
}
