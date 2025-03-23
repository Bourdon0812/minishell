/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:51 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/20 15:45:32 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for update a var already in env
void	update_var(int i, char **env, char *cmd)
{
	char	*new_var;

	new_var = ft_strdup(cmd);
	if (!new_var)
		return ;
	free(env[i]);
	env[i] = new_var;
}

///////////////////////////////////////////////////////////////////////////////
// Function for add a new var to env
void	add_var(t_shell *shell, char *cmd)
{
	int		size;
	char	**new_env;

	size = size_env(shell->envp) + 2;
	copy_env(&new_env, shell->envp, size);
	new_env[size - 2] = ft_strdup(cmd);
	free(shell->envp);
	shell->envp = new_env;
}

///////////////////////////////////////////////////////////////////////////////
// Function for check if a key is already in env
int	var_is_in(char **env, char *path)
{
	int		i;
	char	*var;
	char	*key;
	char	*temp1;
	char	*temp2;

	i = 0;
	temp1 = ft_strchr(path, '=');
	key = ft_strndup(path, temp1 - path);
	while (env[i])
	{
		temp2 = ft_strchr(env[i], '=');
		var = ft_strndup(env[i], temp2 - env[i]);
		if (ft_strcmp(var, key) == 0)
			return (free(var), free(key), i);
		free(var);
		i++;
	}
	free(key);
	return (-1);
}

///////////////////////////////////////////////////////////////////////////////
// start the good function for export (add ou update)
void	start_exp(int i, t_shell *shell)
{
	int	in;

	in = var_is_in(shell->envp, shell->cmd[i]);
	if (in >= 0)
		update_var(in, shell->envp, shell->cmd[i]);
	else
		add_var(shell, shell->cmd[i]);
}

///////////////////////////////////////////////////////////////////////////////
// function for export a list of args (type VAR="the value")
void	exe_export(t_shell *shell, char **args)
{
	int		i;
	char	*temp;

	i = 1;
	print_env(shell);
	while (shell->cmd[i])
	{
		if (!ft_strchr(shell->cmd[i], '='))
		{
			temp = ft_strjoin(shell->cmd[i], "=''");
			free(shell->cmd[i]);
			shell->cmd[i] = temp;
		}
		if (!is_valid_varname(shell->cmd[i]))
		{
			ft_printf("Minishell: export: ");
			ft_printf("%s : not a valid identifier\n", shell->cmd[i]);
		}
		else
			start_exp(i, shell);
		i++;
	}
}
