/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:40 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/08 16:57:59 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_env(char **envp, char *key)
{
	int		i;
	size_t	len;

	if (!envp || !key)
		return (NULL);
	len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], key, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	has_home(t_shell *shell)
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

static void	update_env(t_shell *shell, char *key, char *new_value)
{
	int		i;
	char	*tmp;

	if (!shell->envp || !key || !new_value)
		return ;
	i = -1;
	tmp = ft_strjoin(ft_strjoin(key, "="), new_value);
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
}

int	exe_cd(t_shell *shell, char **args)
{
	char	*new_path;
	char	*old_pwd;

	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		new_path = get_env(shell->envp, "HOME");
		if (has_home(shell))
			return (0);
	}
	else if (!ft_strcmp(args[1], "-"))
		new_path = get_env(shell->envp, "OLDPWD");
	else
		new_path = args[1];
	if (!new_path || chdir(new_path) != 0)
	{
		perror("cd");
		return (1);
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (1);
	update_env(shell, "OLDPWD", get_env(shell->envp, "PWD"));
	update_env(shell, "PWD", old_pwd);
	free(old_pwd);
	return (0);
}
