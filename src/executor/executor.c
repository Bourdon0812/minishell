/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/05 15:42:02 by yseguin          ###   ########.fr       */
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
		binaries_in_out(shell, STDIN_FILENO, STDOUT_FILENO);
}
