/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:33:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/23 15:46:37 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_lexer(t_shell *shell)
{
	int		i;
	int		j;
	int		count;
	char	**new_cmd;

	i = -1;
	count = 0;
	while (shell->cmd[++i] != NULL)
		if (ft_strlen(shell->cmd[i]) != 0)
			count++;
	new_cmd = malloc(sizeof(char *) * (count + 1));
	if (new_cmd == NULL)
		return ;
	i = -1;
	j = 0;
	while (shell->cmd[++i] != NULL)
	{
		if (ft_strlen(shell->cmd[i]) != 0)
			new_cmd[j++] = shell->cmd[i];
		else
			free(shell->cmd[i]);
	}
	new_cmd[j] = NULL;
	free(shell->cmd);
	shell->cmd = new_cmd;
}

char	*clean_arg(char *arg, int keep_quotes)
{
	char	*arg_clean;

	if (!arg)
		return (NULL);
	if (keep_quotes == 0)
	{
		arg_clean = remove_quotes(arg);
		free(arg);
		return (arg_clean);
	}
	return (arg);
}

void	handle_assignment(char *input, int *end)
{
	if (input[*end] == '=' && is_quote(input[*end + 1]))
	{
		(*end)++;
		skip_quotes(input, end, input[*end]);
	}
}

int	parse_argument(char *input, int end)
{
	char	quote;

	quote = input[end];
	end++;
	while (input[end] && input[end] != quote)
		end++;
	if (input[end] == quote)
		end++;
	return (split_args_p2(input, end));
}
