/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:57 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/10 16:48:56 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exe_pwd(t_shell *shell, char **args)
{
	char	*pwd;

	(void)args;
	pwd = get_env_var(shell->envp, "PWD");
	if (!pwd)
	{
		perror("pwd");
		return (1);
	}
	ft_printf("%s\n", pwd);
	return (0);
}
