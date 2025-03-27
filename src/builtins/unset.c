/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:33 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/27 16:45:33 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	rm_var(t_shell *shell, char *var)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(var);
	while (shell->envp[i])
	{
		if (ft_strncmp(shell->envp[i], var, size) == 0)
		{
			free(shell->envp[i]);
			while (shell->envp[i + 1])
			{
				shell->envp[i] = shell->envp[i + 1];
				i++;
			}
			shell->envp[i] = NULL;
			break ;
		}
		i++;
	}
}

void	exe_unset(t_shell *shell, char **args)
{
	int	i;

	i = 0;
	while (args[++i])
		rm_var(shell, args[i]);
	return ;
}
