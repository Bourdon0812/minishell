/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/10 14:08:45 by yseguin          ###   ########.fr       */
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
		launch_bin(shell);
}
