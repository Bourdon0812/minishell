/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/07 15:21:29 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_exit(t_shell *shell, char **args)
{
	int	sig;

	if (args[1])
		sig = ft_atoi(args[1]);
	else
		sig = 0;
	ft_printf("exit\n");
	free_shell(shell);
	exit(sig);
}
