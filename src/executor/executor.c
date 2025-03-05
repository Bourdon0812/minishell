/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/03 18:15:30 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	complex_command(t_shell *shell)
{
	return ;
}

void	simple_command(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->cmd[i] != NULL)
	{
		ft_putnbr_fd(ft_strlen(shell->cmd[i]), 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	if (is_builtins(shell->cmd[0]))
		exe_builtins(shell);
	else
		exe_command(shell);
}