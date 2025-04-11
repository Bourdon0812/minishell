/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:09:07 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/11 16:50:40 by ilbonnev         ###   ########.fr       */
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

///////////////////////////////////////////////////////////////////////////////
// Function for obtain a value from an env var ($VAR)
char	*get_env_value(char *env_var, t_shell *shell)
{
	int		i;
	char	*key;
	char	**envp;
	size_t	len;

	envp = shell->envp;
	if (!env_var || !envp || env_var[0] != '$' || env_var[1] == '\0')
		return (NULL);
	key = &env_var[1];
	len = strlen(key);
	if (env_var[0] == '$' && env_var[1] == '?' && env_var[2] == '\0')
	{
		return (ft_itoa(shell->l_sig));
	}
	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], key, len) == 0 && envp[i][len] == '=')
			return (ft_strdup(&envp[i][len + 1]));
		i++;
	}
	return (NULL);
}
