/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:51 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/11 13:40:07 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

///////////////////////////////////////////////////////////////////////////////
// Function for update a var already in env
void	update_var(int i, char ***env, char *cmd)
{
	char *new_var;

	new_var = ft_strdup(cmd);
	if (!new_var)
		return;
	free((*env)[i]);
	(*env)[i] = new_var;
}

///////////////////////////////////////////////////////////////////////////////
// Function for add a new var to env
void	add_var()
{
	return ;
}

///////////////////////////////////////////////////////////////////////////////
// Function for check if a key is already in env
int var_is_in(char **env, char *path)
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
// function for export a list of args (type VAR="the value")
void	exe_export(t_shell *shell)
{
	int		i;
	int		in;
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
			ft_printf("Minishell: export: %s : not a valid identifier\n", shell->cmd[i]);
		else
		{
			in = var_is_in(shell->envp, shell->cmd[i]);
			if (in >= 0)
				update_var(in, &(shell->envp), shell->cmd[i]);
			else
				add_var();
		}
		i++;
	}
}
