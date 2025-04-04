/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:09:07 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/04 17:16:06 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*add_shlvl(char *env)
{
	char	*tmp;
	char	*res;

	if (ft_strncmp(env, "SHLVL=", 6) == 0)
	{
		tmp = ft_itoa(ft_atoi(env + 6) + 1);
		if (!tmp)
			return (ft_strdup(env));
		res = ft_strjoin("SHLVL=", tmp);
		free(tmp);
		return (res);
	}
	return (ft_strdup(env));
}
