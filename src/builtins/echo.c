/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:53:08 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/10 16:58:35 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_backslash(const char *arg, int *i)
{
	write(1, &arg[*i + 1], 1);
	*i += 2;
}

static void	handle_dollar(const char *arg, int *i, t_shell *shell)
{
	int		start;
	char	*name;
	char	*with_dollar;
	char	*value;

	(*i)++;
	start = *i;
	while (arg[*i] && (ft_isalnum(arg[*i]) || arg[*i] == '_'))
		(*i)++;
	if (start == *i)
		write(1, "$", 1);
	else
	{
		name = ft_substr(arg, start, *i - start);
		with_dollar = ft_strjoin("$", name);
		free(name);
		value = get_env_value(with_dollar, shell);
		free(with_dollar);
		if (value)
		{
			write(1, value, ft_strlen(value));
			free(value);
		}
	}
}

static void	print_argument(char *arg, t_shell *shell)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\\' && arg[i + 1])
			handle_backslash(arg, &i);
		else if (arg[i] == '$')
			handle_dollar(arg, &i, shell);
		else
			write(1, &arg[i++], 1);
	}
}

int	exe_echo(t_shell *shell, char **args)
{
	int	i;
	int	newline_flag;

	(void)shell;
	i = skip_n_flags(args, &newline_flag);
	while (args[i])
	{
		print_argument(args[i], shell);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline_flag)
		write(1, "\n", 1);
	return (0);
}
