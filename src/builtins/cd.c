/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:40 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/11 16:52:15 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	has_home(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->envp[i])
	{
		if (!ft_strncmp(shell->envp[i], "HOME=", 5))
			return (0);
		i++;
	}
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// 
static void	update_env(t_shell *shell, char *key, char *new_value)
{
	int		i;
	char	*tmp;
	char	*joined;

	if (shell->envp == NULL || key == NULL || new_value == NULL)
		return ;
	i = -1;
	joined = ft_strjoin(key, "=");
	if (!joined)
		return ;
	tmp = ft_strjoin(joined, new_value);
	free(joined);
	if (!tmp)
		return ;
	while (shell->envp[++i])
	{
		if (!ft_strncmp(shell->envp[i], key, ft_strlen(key))
			&& shell->envp[i][ft_strlen(key)] == '=')
		{
			free(shell->envp[i]);
			shell->envp[i] = tmp;
			return ;
		}
	}
	free(tmp);
}

///////////////////////////////////////////////////////////////////////////////
// second part of cd
int	cd_p2(t_shell *shell, char **old_pwd, char **new_path)
{
	char	*temp;

	*old_pwd = getcwd(NULL, 0);
	if (!(*old_pwd))
	{
		free(*new_path);
		return (1);
	}
	temp = get_env_value("$PWD", shell);
	update_env(shell, "OLDPWD", temp);
	update_env(shell, "PWD", *old_pwd);
	free(*old_pwd);
	free(temp);
	free(*new_path);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// Function that imitate "cd"
int	exe_cd(t_shell *shell, char **args)
{
	char	*new_path;
	char	*old_pwd;

	new_path = NULL;
	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		if (has_home(shell))
			return (0);
		new_path = get_env_value("$HOME", shell);
	}
	else if (!ft_strcmp(args[1], "-"))
		new_path = get_env_value("$OLDPWD", shell);
	else
		new_path = ft_strdup(args[1]);
	if (!new_path || chdir(new_path) != 0)
	{
		perror("cd");
		if (new_path)
			free(new_path);
		return (1);
	}
	return (cd_p2(shell, &old_pwd, &new_path));
}
