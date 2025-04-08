/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:14:28 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/08 17:21:15 by yseguin          ###   ########.fr       */
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
