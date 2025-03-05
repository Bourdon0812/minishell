/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:41:11 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/03 17:36:27 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_builtins(t_shell *shell)
{
	if (ft_strcmp(shell->cmd[0], "echo") == 0)
		exe_echo(shell);
	else if (ft_strcmp(shell->cmd[0], "cd") == 0)
		exe_cd(shell);
	else if (ft_strcmp(shell->cmd[0], "pwd") == 0)
		exe_pwd(shell);
	else if (ft_strcmp(shell->cmd[0], "export") == 0)
		exe_export(shell);
	else if (ft_strcmp(shell->cmd[0], "env") == 0)
		exe_env(shell);
	else if (ft_strcmp(shell->cmd[0], "exit") == 0)
		exe_exit(shell);
	else if (ft_strcmp(shell->cmd[0], "unset") == 0)
		exe_unset(shell);
}
