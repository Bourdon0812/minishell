/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:41:11 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/20 15:46:15 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
