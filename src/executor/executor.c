/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/10 15:43:25 by yseguin          ###   ########.fr       */
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
