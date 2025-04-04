/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:46 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/04 17:04:47 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exe_env(t_shell *shell, char **args)
{
	int	i;

	(void)args;
	i = -1;
	if (!(shell->envp))
		return (1);
	while (shell->envp[++i])
		if (ft_strchr(shell->envp[i], '='))
			ft_printf("%s\n", shell->envp[i]);
	return (0);
}
