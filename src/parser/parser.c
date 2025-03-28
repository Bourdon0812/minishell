/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:12:37 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/12 17:18:40 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	allocate_and_copy_args(t_cmd *cmd, char *arg)
{
	int		i;
	char	**new_args;

	i = 0;
	while (cmd->args[i] != NULL)
		i++;
	new_args = malloc(sizeof(char *) * (i + 2));
	if (new_args == NULL)
		return ;
	i = -1;
	while (cmd->args[++i] != NULL)
		new_args[i] = cmd->args[i];
	new_args[i] = ft_strdup(arg);
	if (!new_args[i])
	{
		free(new_args);
		return ;
	}
	new_args[i + 1] = NULL;
	free(cmd->args);
	cmd->args = new_args;
}

void	add_argument(t_cmd *cmd, char *arg)
{
	if (cmd->args == NULL)
	{
		cmd->args = malloc(sizeof(char *) * 2);
		if (cmd->args == NULL)
			return ;
		cmd->args[0] = ft_strdup(arg);
		cmd->args[1] = NULL;
		return ;
	}
	allocate_and_copy_args(cmd, arg);
}

void	handle_redirections(t_cmd *cmd, char **cmds, int *i)
{
	if (!ft_strcmp(cmds[*i], "<") && cmds[*i + 1])
		cmd->input_file = ft_strdup(cmds[++(*i)]);
	else if (!ft_strcmp(cmds[*i], ">") && cmds[*i + 1])
	{
		cmd->output_file = ft_strdup(cmds[++(*i)]);
		cmd->append = 0;
	}
	else if (!ft_strcmp(cmds[*i], ">>") && cmds[*i + 1])
	{
		cmd->output_file = ft_strdup(cmds[++(*i)]);
		cmd->append = 1;
	}
	else if (!ft_strcmp(cmds[*i], "<<") && cmds[*i + 1])
		cmd->heredoc = ft_strdup(cmds[++(*i)]);
	else
		ft_putstr_fd("Minishell: erreur de syntaxe\n", 2);
}

int	check_syntax_errors(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		if ((cmds[i][0] == '|' || cmds[i][0] == '<' || cmds[i][0] == '>')
			&& (!cmds[i + 1] || cmds[i + 1][0] == '|' || cmds[i + 1][0] == '<'
			|| cmds[i + 1][0] == '>'))
		{
			ft_putstr_fd("Minishell: erreur de syntaxe", 2);
			ft_putstr_fd(cmds[i], 2);
			ft_putchar_fd('\n', 2);
			return (1);
		}
		i++;
	}
	return (0);
}

t_cmd	*parsing(t_shell *shell)
{
	t_cmd	*head;
	t_cmd	*current;
	int		i;

	head = new_cmd();
	if (check_syntax_errors(shell->cmd) || head == NULL)
		return (NULL);
	current = head;
	i = -1;
	while (shell->cmd[++i])
	{
		if (!ft_strcmp(shell->cmd[i], "|"))
		{
			current->pipe = 1;
			current->next = new_cmd();
			if (!current->next)
				return (NULL);
			current = current->next;
		}
		else if (shell->cmd[i][0] == '<' || shell->cmd[i][0] == '>')
			handle_redirections(current, shell->cmd, &i);
		else
			add_argument(current, shell->cmd[i]);
	}
	return (head);
}
