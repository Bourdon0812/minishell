/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/12 17:21:28 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for complexe command
void	complex_command(t_shell *shell, t_cmd *cmd)
{
	return ;
}

///////////////////////////////////////////////////////////////////////////////
// Function for the single command without >>, <, | 
void	simple_command(t_shell *shell)
{
	if (is_builtins(shell->cmd[0]))
		exe_builtins(shell);
	else
	{
		if (check_cmd(shell) == 0)
			ft_printf("%s : command not found\n", shell->cmd[0]);
		else
			launch_bin(shell);
	}
}
