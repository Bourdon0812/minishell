/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:14:28 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/08 18:37:29 by yseguin          ###   ########.fr       */
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
