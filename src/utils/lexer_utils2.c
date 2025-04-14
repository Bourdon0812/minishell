/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:14:28 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/14 11:09:39 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// function for check bad input.
int	is_empty(char *input)
{
	if (ft_strcmp(input, "\"\"") == 0)
		return (ft_printf("Minishell: \'\': command not found\n"), 1);
	if (ft_strcmp(input, "\'\'") == 0)
		return (ft_printf("Minishell: \'\': command not found\n"), 1);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// Function for clean all t_cmd datas after execution
void	free_cmd(t_cmd *cmd)
{
	int	i;

	if (!cmd)
		return ;
	i = 0;
	if (cmd->args)
	{
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
	}
	i = 0;
	if (cmd->heredocs)
	{
		while (cmd->heredocs[i])
			free(cmd->heredocs[i++]);
		free(cmd->heredocs);
	}
	if (cmd->input_file)
		free(cmd->input_file);
	if (cmd->output_file)
		free(cmd->output_file);
	free(cmd);
}

int	check_last_arg(t_shell *shell)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (shell->cmd[i] != NULL)
	{
		if (ft_strlen(shell->cmd[i]) > 1
			&& ft_strchr(shell->cmd[i], '|') != NULL)
		{
			printf("syntax error\n");
			return (0);
		}
		i++;
	}
	i = i - 1;
	if (i <= 0)
		return (1);
	while (shell->cmd[i][i2] != '\0')
	{
		if (shell->cmd[i][i2] == '|')
			return (0);
		i2++;
	}
	return (1);
}
