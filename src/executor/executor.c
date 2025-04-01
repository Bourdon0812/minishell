/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:37:44 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/01 16:23:53 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// Function for wait all process in complex_cmd
static void	wait_children(pid_t *pids, pid_t last, int count, t_shell *shell)
{
	int	i;

	i = 0;
	while (i < count)
	{
		wait_all(pids[i], last, shell);
		i++;
	}
}

///////////////////////////////////////////////////////////////////////////////
// Function for select the good action in complex_cmd
static void	handle_command_node(t_shell *shell, t_cmd *cmd, t_exec_ctx *ctx)
{
	pid_t	pid;

	if (cmd->next)
		pid = good_with_pip(shell, cmd, &ctx->prev, ctx->fd);
	else
		pid = good_rep(shell, cmd, ctx->prev, STDOUT_FILENO);
	if (pid == -1)
		return ;
	ctx->pids[ctx->i] = pid;
	ctx->last = pid;
	ctx->i++;
}

///////////////////////////////////////////////////////////////////////////////
// Function for complexe command
void	complex_command(t_shell *shell, t_cmd *cmd)
{
	t_exec_ctx	ctx;

	ctx.i = 0;
	ctx.prev = 0;
	while (cmd)
	{
		if (g_signal != NEUTRAL_SIGINT)
		{
			g_signal = NEUTRAL_SIGINT;
			return ;
		}
		if (check_cmd(cmd->args, shell) != 0)
			handle_command_node(shell, cmd, &ctx);
		cmd = cmd->next;
	}
	if (ctx.prev != 0)
		close(ctx.prev);
	wait_children(ctx.pids, ctx.last, ctx.i, shell);
}

///////////////////////////////////////////////////////////////////////////////
// Function for the single command without >>, <, | 
void	simple_command(t_shell *shell)
{
	pid_t	pid;
	int		status;

	if (is_builtins(shell->cmd[0]))
		exe_builtins(shell, shell->cmd);
	else
	{
		if (check_cmd(shell->cmd, shell) == 0)
			return ;
		else
		{
			pid = launch_bin(shell, shell->cmd, STDIN_FILENO, STDOUT_FILENO);
			wait_all(pid, pid, shell);
		}
	}
}
