/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:46 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/31 16:39:06 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_env(t_shell *shell, char **args)
{
	int	i;

	(void)args;
	i = -1;
	if (!(shell->envp))
		return ;
	while (shell->envp[++i])
		if (ft_strchr(shell->envp[i], '='))
			ft_printf("%s\n", shell->envp[i]);
}
