/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:41:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/14 10:19:56 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_args(char *input)
{
	int	i;
	int	args;

	i = 0;
	args = 0;
	while (input[i])
	{
		while (ft_iswsp(input[i]))
			i++;
		if (!input[i])
			break ;
		args++;
		if (is_quote(input[i]))
			skip_quotes(input, &i, input[i]);
		while (input[i] && !ft_iswsp(input[i]) && !is_quote(input[i]))
			i++;
	}
	return (args);
}

char	*get_arg(char *input, int start, int end, int keep_quotes)
{
	char	*arg;

	arg = ft_substr(input, start, end - start);
	return (clean_arg(arg, keep_quotes));
}

int	split_args_p2(char *input, int end)
{
	while (input[end] && !ft_iswsp(input[end]))
	{
		handle_assignment(input, &end);
		if (!input[end])
			break ;
		end++;
	}
	return (end);
}

char	**split_args(char *input, int keep_quotes)
{
	char	**cmd;
	int		start;
	int		end;
	int		k;

	if (input == NULL || *input == '\0')
		return (NULL);
	end = 0;
	k = -1;
	cmd = malloc(sizeof(char *) * (count_args(input) + 1));
	while (input[end])
	{
		while (ft_iswsp(input[end]) && input[end])
			end++;
		start = end;
		if (is_quote(input[end]))
			end = parse_argument(input, end);
		else
			end = split_args_p2(input, end);
		if (start < end)
			cmd[++k] = get_arg(input, start, end, keep_quotes);
	}
	cmd[++k] = NULL;
	return (cmd);
}

void	lexer(t_shell *shell)
{
	int		keep_quotes;
	char	*input_cpy;

	if (!shell->input || is_empty(shell->input))
		return ;
	input_cpy = ft_strdup(shell->input);
	if (!input_cpy)
		return ;
	keep_quotes = (!ft_strncmp(shell->input, "echo", 4)
			&& (shell->input[4] == ' ' || shell->input[4] == '\0'));
	shell->cmd = split_args(input_cpy, keep_quotes);
	free(input_cpy);
	if (!shell->cmd || !shell->cmd[0])
		return ;
	clear_lexer(shell);
	if (!shell->cmd || (!shell->cmd[0] && !shell->cmd[1])
		|| shell->cmd[0][0] == '|'
		|| shell->cmd[0][ft_strlen(shell->cmd[0]) - 1] == '|')
		return ;
	if (has_redirection(shell->input) || has_pipe(shell->input))
		complex_command(shell, parsing(shell));
	else
		simple_command(shell);
}
