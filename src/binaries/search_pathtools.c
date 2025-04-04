/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pathtools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:49:41 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/04 17:04:53 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// init and check args before search_path, and return error if needed
static int	init_path_search(char *c, t_shell *s, char ***p, char ***args)
{
	char	*tmp;

	if (!c || !s)
		return (0);
	tmp = get_env_value("$PATH", s);
	if (!tmp)
		return (0);
	*p = ft_split(tmp, ':');
	free(tmp);
	if (!*p)
		return (0);
	*args = ft_split(c, ' ');
	if (!*args)
		return (ft_free_tab(*p), 0);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Search the good path for a cmd with the good method (not which xD)
char	*search_path(char *cmd, t_shell *shell, int i)
{
	char	*tmp;
	char	*bin;
	char	**args;
	char	**paths;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	if (!init_path_search(cmd, shell, &paths, &args))
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		bin = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (bin && access(bin, F_OK | X_OK) == 0)
			return (ft_free_tab(paths), ft_free_tab(args), bin);
		free(bin);
		i++;
	}
	return (ft_free_tab(paths), ft_free_tab(args), NULL);
}
