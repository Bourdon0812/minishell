/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/04 17:04:46 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_exit(t_shell *shell, char **args)
{
	if (args[1])
	{
		exit(ft_atoi(args[1]));
	}
	else
	{
		exit(0);
	}
}
