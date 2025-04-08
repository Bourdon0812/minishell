/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:09:07 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/08 18:38:11 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// update the shLVL at the start of project
char	*add_shlvl(char *env)
{
	char	*tmp;
	char	*res;

	if (ft_strncmp(env, "SHLVL=", 6) == 0)
	{
		tmp = ft_itoa(ft_atoi(env + 6) + 1);
		if (!tmp)
			return (ft_strdup(env));
		res = ft_strjoin("SHLVL=", tmp);
		free(tmp);
		return (res);
	}
	return (ft_strdup(env));
}

///////////////////////////////////////////////////////////////////////////////
// Function for clean shell struct at the end of shell or a cmd (use mod var)
void	free_shell(t_shell *shell, int mode)
{
	if (!shell)
		return ;
	if (shell->envp && !mode)
		ft_free_tab(shell->envp);
	if (shell->input)
		free(shell->input);
	if (shell->cmd)
	{
		ft_free_tab(shell->cmd);
		shell->cmd = NULL;
	}
}
