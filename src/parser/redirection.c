/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:05:04 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/04 16:06:17 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_input_redirection(t_cmd *cmd, char **cmds, int *i)
{
	if (!ft_strcmp(cmds[*i], "<") && cmds[*i + 1])
		cmd->input_file = ft_strdup(cmds[++(*i)]);
}

static void	handle_output_redirection(t_cmd *cmd, char **cmds, int *i)
{
	if (!ft_strcmp(cmds[*i], ">") && cmds[*i + 1])
	{
		cmd->output_file = ft_strdup(cmds[++(*i)]);
		cmd->append = 0;
	}
	else if (!ft_strcmp(cmds[*i], ">>") && cmds[*i + 1])
	{
		cmd->output_file = ft_strdup(cmds[++(*i)]);
		cmd->append = 1;
	}
}

static void	add_heredoc(t_cmd *cmd, char *heredoc)
{
	int		j;
	char	**new_heredocs;

	new_heredocs = malloc(sizeof(char *) * (cmd->heredoc_count + 2));
	if (!new_heredocs)
		return ;
	j = 0;
	while (j < cmd->heredoc_count)
	{
		new_heredocs[j] = cmd->heredocs[j];
		j++;
	}
	new_heredocs[cmd->heredoc_count] = ft_strdup(heredoc);
	new_heredocs[cmd->heredoc_count + 1] = NULL;
	free(cmd->heredocs);
	cmd->heredocs = new_heredocs;
	cmd->heredoc_count++;
}

static void	handle_heredoc_redirection(t_cmd *cmd, char **cmds, int *i)
{
	if (!ft_strcmp(cmds[*i], "<<") && cmds[*i + 1])
		add_heredoc(cmd, cmds[++(*i)]);
}

void	handle_redirections(t_cmd *cmd, char **cmds, int *i)
{
	handle_input_redirection(cmd, cmds, i);
	handle_output_redirection(cmd, cmds, i);
	handle_heredoc_redirection(cmd, cmds, i);
}
