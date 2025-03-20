/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:33:49 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/20 15:01:54 by ilbonnev         ###   ########.fr       */
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
