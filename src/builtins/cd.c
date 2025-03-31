/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:40 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/31 17:27:33 by ilbonnev         ###   ########.fr       */
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

void	exe_cd(t_shell *shell, char **args)
{
	char	*new_path;
	char	*old_pwd;

	if (args[1] == NULL || !ft_strcmp(args[1], "~"))
		new_path = getenv("HOME");
	else if (!ft_strcmp(args[1], "-"))
		new_path = getenv("OLDPWD");
	else
		new_path = args[1];
	if (new_path == NULL || chdir(new_path) != 0)
	{
		perror("cd");
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	if (old_pwd == NULL)
		return ;
	update_env(shell, "OLDPWD", getenv("PWD"));
	update_env(shell, "PWD", old_pwd);
	free(old_pwd);
}
