/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:38:12 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/04 17:04:27 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	ft_iswsp(int c)
{
	return (
		c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\r'
		|| c == '\v'
		|| c == '\f'
	);
}

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	has_pipe(char *input)
{
	return (ft_strstr(input, "|") != NULL);
}

int	has_redirection(char *input)
{
	return (
		ft_strstr(input, ">") != NULL
		|| ft_strstr(input, ">>") != NULL
		|| ft_strstr(input, "<") != NULL
		|| ft_strstr(input, "<<") != NULL
	);
}
