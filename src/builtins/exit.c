/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/11 16:45:00 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	nb_arg(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

void	exe_exit(t_shell *shell, char **args)
{
	int	sig;

	sig = 0;
	if (nb_arg(args) <= 2)
	{
		if (args[1])
		{
			sig = ft_atoi(args[1]);
			if (sig == 0 && args[1][0] != '0')
			{
				ft_printf("exit: invalid number: %s\n", args[1]);
				return ;
			}
		}
		ft_printf("exit\n");
		free_shell(shell, 0);
		exit(sig % 256);
	}
	else
		ft_printf("exit: too many arguments\n");
}
