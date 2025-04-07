/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/07 09:58:29 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exe_exit(char **args)
{
	ft_printf("exit\n");
	if (args[1])
	{
		exit(ft_atoi(args[1]));
	}
	else
	{
		exit(0);
	}
}
