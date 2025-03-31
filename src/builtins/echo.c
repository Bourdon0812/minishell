/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:53:08 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/31 18:33:45 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*allocate_result(char *str)
{
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	*rm_quotes(char *str)
{
	int		i;
	int		j;
	char	quote;
	char	*result;

	result = allocate_result(str);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				result[j++] = str[i++];
			if (str[i])
				i++;
		}
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

int	skip_n_flags(char **args, int *newline_flag)
{
	int	i;
	int	j;

	i = 1;
	*newline_flag = 1;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		*newline_flag = 0;
		i++;
	}
	return (i);
}

void	print_argument(char *arg)
{
	char	*env_value;
	char	*clean_arg;

	if (arg[0] == '$')
	{
		env_value = get_env_value(arg);
		if (env_value)
		{
			write(1, env_value, ft_strlen(env_value));
			free(env_value);
		}
	}
	else
	{
		clean_arg = rm_quotes(arg);
		write(1, clean_arg, ft_strlen(clean_arg));
		free(clean_arg);
	}
}

void	exe_echo(t_shell *shell, char **args)
{
	int	i;
	int	newline_flag;

	(void)shell;
	i = skip_n_flags(args, &newline_flag);
	while (args[i])
	{
		print_argument(args[i]);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline_flag)
		write(1, "\n", 1);
}
