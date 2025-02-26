/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:12:37 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/02/21 02:14:17 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* TODO call by lexer */
void	command(t_shell *shell)
{
	if (is_builtins(shell->cmd[0]))
		exe_builtins(shell);
	else
		exe_command(shell);
}
