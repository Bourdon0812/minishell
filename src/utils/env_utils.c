/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:08:57 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/10 17:00:03 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for obtain se length of env
int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

///////////////////////////////////////////////////////////////////////////////
// Function for copy the env (needed for edit with export and unset)
int	copy_env(char ***nenv, char **env, int size)
{
	int	i;

	*nenv = malloc(sizeof(char *) * (size + 1));
	if (!(*nenv))
		return (0);
	i = 0;
	while (env[i])
	{
		(*nenv)[i] = add_shlvl(env[i]);
		if (!(*nenv)[i])
		{
			while (--i >= 0)
				free((*nenv)[i]);
			free(*nenv);
			return (0);
		}
		i++;
	}
	(*nenv)[i] = NULL;
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

///////////////////////////////////////////////////////////////////////////////
// Function for check if the given arg is valid for export
int	is_valid_varname(char *name)
{
	int	i;
	int	equal;

	i = 0;
	equal = 0;
	if (!name || (!ft_isalpha(name[0]) && name[0] != '_'))
		return (0);
	while (name[i])
	{
		if (!equal && name[i] == '=')
			equal = 1;
		if (!ft_isalnum(name[i]) && name[i] != '_' && !equal)
			return (0);
		i++;
	}
	return (1);
}
