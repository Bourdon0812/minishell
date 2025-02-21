/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:38:12 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/02/21 02:10:03 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtins(char *str)
{
	int					i;
	static const char	*builtins[] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"env",
		"exit",
		"unset",
		NULL
	};

	i = 0;
	while (builtins[i] != NULL)
	{
		if (strcmp(str, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
