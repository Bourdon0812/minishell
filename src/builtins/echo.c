/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:53:08 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/14 01:36:24 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_backslash(const char *arg, int *i)
{
	write(1, &arg[*i + 1], 1);
	*i += 2;
}

static int	print_exit_code_if_needed(const char *arg, int *i, t_shell *shell)
{
	char	*exit_code_str;

	if (arg[*i] == '?')
	{
		exit_code_str = ft_itoa(shell->l_sig);
		if (exit_code_str)
		{
			write(1, exit_code_str, ft_strlen(exit_code_str));
			free(exit_code_str);
		}
		(*i)++;
		return (1);
	}
	return (0);
}

void	handle_dollar(const char *arg, int *i, t_shell *shell)
{
	int	start;

	(*i)++;
	start = *i;
	if (print_exit_code_if_needed(arg, i, shell))
		return ;
	while (arg[*i] && (ft_isalnum(arg[*i]) || arg[*i] == '_'))
		(*i)++;
	expand_env_variable(arg, i, start, shell);
}

void	print_argument(char *arg, t_shell *shell)
{
	int		i;
	char	quote;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\'' || arg[i] == '"')
		{
			quote = arg[i++];
			print_inside_quotes(arg, &i, quote, shell);
		}
		else if (arg[i] == '\\' && arg[i + 1])
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
