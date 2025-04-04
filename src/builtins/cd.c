/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:40 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/04 17:04:50 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	update_env(t_shell *shell, char *key, char *new_value)
{
	int		i;
	char	*tmp;
	char	*new_entry;

	if (shell->envp == NULL)
		return ;
	i = -1;
	new_entry = ft_strjoin(key, "=");
	tmp = ft_strjoin(new_entry, new_value);
	free(new_entry);
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

int	has_home(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->envp[++i] != NULL)
		if (ft_strncmp((const char *)shell->envp[i], "HOME", 4) != 0)
			return (1);
	return (0);
}

int	exe_cd(t_shell *shell, char **args)
{
	char	*new_path;
	char	*old_pwd;

	if (args[1] == NULL || !ft_strcmp(args[1], "~"))
	{
		new_path = getenv("HOME");
		if (has_home(shell) == 1)
			return (0);
	}
	else if (!ft_strcmp(args[1], "-"))
		new_path = getenv("OLDPWD");
	else
		new_path = args[1];
	if (new_path == NULL || chdir(new_path) != 0)
	{
		perror("cd");
		return (1);
	}
	old_pwd = getcwd(NULL, 0);
	if (old_pwd == NULL)
		return (1);
	update_env(shell, "OLDPWD", getenv("PWD"));
	update_env(shell, "PWD", old_pwd);
	free(old_pwd);
	return (0);
}
