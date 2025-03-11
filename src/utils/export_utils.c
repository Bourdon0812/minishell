/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:08:57 by yseguin           #+#    #+#             */
/*   Updated: 2025/03/11 13:38:26 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for copy the env (needed for edit with export and unset)
int	copy_env(t_shell *shell, char **env)
{
	int	i;
	int	count;

	count = 0;
	while (env[count])
		count++;
	shell->envp = malloc(sizeof(char *) * (count + 1));
	if (!shell->envp)
		return (0);
	i = 0;
	while (env[i])
	{
		shell->envp[i] = strdup(env[i]);
		i++;
	}
	shell->envp[i] = NULL;
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Function for print env
void	print_env(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->cmd[i])
		i++;
	if (i == 1)
	{
		i = 0;
		while (shell->envp[i])
		{
			ft_printf("%s\n", shell->envp[i]);
			i++;
		}
	}
}