/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:57 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/08 17:21:13 by ilbonnev         ###   ########.fr       */
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

int	exe_pwd(t_shell *shell, char **args)
{
	char	*pwd;

	(void)args;
	pwd = get_env(shell->envp, "PWD");
	if (!pwd)
	{
		perror("pwd");
		return (1);
	}
	ft_printf("%s\n", pwd);
	return (0);
}
