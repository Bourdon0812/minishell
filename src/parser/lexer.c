/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:41:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/10 16:37:34 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_args(char *input, int keep_quotes)
{
	int	i;
	int	args;

	i = 0;
	args = 0;
	while (input[i] != '\0')
	{
		while (ft_iswsp(input[i]))
			i++;
		if (input[i] == '\0')
			break ;
		args++;
		if (is_quote(input[i]))
			skip_quotes(input, &i, input[i]);
		while (input[i] != '\0'
			&& !ft_iswsp(input[i])
			&& !is_quote(input[i])
		)
			i++;
	}
	return (args);
}

char	*get_arg(char *input, int start, int end, int keep_quotes)
{
	char	*arg;
	char	*arg_clean;

	arg = ft_substr(input, start, end - start);
	if (arg == NULL)
		return (NULL);
	if (keep_quotes == 0)
	{
		arg_clean = remove_quotes(arg);
		free(arg);
		return (arg_clean);
	}
	return (arg);
}

void	split_args_p2(char *input, int *end)
{
	while (input[*end] != '\0' && !ft_iswsp(input[*end]))
	{
		if (input[*end] == '=' && is_quote(input[*end + 1]))
		{
			(*end)++;
			skip_quotes(input, end, input[*end]);
			break;
		}
		(*end)++;
	}
}

char	**split_args(char *input, int keep_quotes)
{
	char	**cmd;
	int		start;
	int		end;
	int		k;

	end = 0;
	k = -1;
	cmd = malloc(sizeof(char *) * (count_args(input, keep_quotes) + 1));
	if (cmd == NULL)
		return (NULL);
	while (input[end] != '\0')
	{
		while (ft_iswsp(input[end]) && input[end] != '\0')
			end++;
		start = end;
				if (is_quote(input[end]))
			skip_quotes(input, &end, input[end]);
		else
			split_args_p2(input, &end);
		cmd[++k] = get_arg(input, start, end, keep_quotes);
	}
	cmd[++k] = NULL;
	return (cmd);
}

void	lexer(t_shell *shell)
{
	int		keep_quotes;
	char	*input_cpy;

	if (shell->input == NULL)
		return ;
	input_cpy = ft_strdup(shell->input);
	if (input_cpy == NULL)
		return ;
	keep_quotes = (!ft_strncmp(shell->input, "echo", 4)
			&& (shell->input[4] == ' ' || shell->input[4] == '\0'));
	shell->cmd = split_args(input_cpy, keep_quotes);
	free(input_cpy);
	if (shell->cmd == NULL || shell->cmd[0] == NULL)
		return ;
	if (has_redirection(shell->input) || has_pipe(shell->input))
		complex_command(shell);
	else
		simple_command(shell);
}
