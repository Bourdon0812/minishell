/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:01 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/14 02:02:42 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_var(int i, char **env, char *cmd)
{
	char	*new_var;

	new_var = ft_strdup(cmd);
	if (!new_var)
		return ;
	free(env[i]);
	env[i] = new_var;
}

void	add_var(t_shell *shell, char *cmd)
{
	int		size;
	char	**new_env;

	size = size_env(shell->envp) + 2;
	copy_env(&new_env, shell->envp, size);
	new_env[size - 2] = ft_strdup(cmd);
	new_env[size - 1] = NULL;
	free(shell->envp);
	shell->envp = new_env;
}

char	*get_env_key(char *entry)
{
	char	*eq;
	char	*key;

	eq = ft_strchr(entry, '=');
	if (!eq)
		return (NULL);
	key = ft_strndup(entry, eq - entry);
	return (key);
}

int	check_match(char **env, char *key)
{
	int		i;
	char	*var;

	i = 0;
	while (env[i])
	{
		var = get_env_key(env[i]);
		if (!var)
			return (-1);
		if (ft_strcmp(var, key) == 0)
		{
			free(var);
			return (i);
		}
		free(var);
		i++;
	}
	return (-1);
}

int	var_is_in(char **env, char *path)
{
	char	*key;
	int		index;

	key = get_env_key(path);
	if (!key)
		return (-1);
	index = check_match(env, key);
	free(key);
	return (index);
}
