/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pathtools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:49:41 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/14 00:40:28 by ilbonnev         ###   ########.fr       */
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

char	*search_in_paths(char **paths, char **args)
{
	char	*tmp;
	char	*bin;
	int		i;

	i = -1;
	while (paths[++i])
	{
		if (!paths[i] || !args[0])
			continue ;
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		bin = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (bin)
		{
			if (access(bin, F_OK | X_OK) == 0)
				return (bin);
			free(bin);
		}
	}
	return (NULL);
}

char	*search_path(char *cmd, t_shell *shell, int i)
{
	char	**args;
	char	**paths;
	char	*bin;

	(void)i;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	if (!init_path_search(cmd, shell, &paths, &args))
		return (NULL);
	bin = search_in_paths(paths, args);
	ft_free_tab(paths);
	ft_free_tab(args);
	return (bin);
}
