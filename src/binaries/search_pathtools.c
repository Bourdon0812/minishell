/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pathtools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:49:41 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/01 14:34:50 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

///////////////////////////////////////////////////////////////////////////////
// init and check args before search_path, and return error if needed
int	init_path_search(char *cmd, t_shell *shell, char ***paths, char ***args)
{
	char	*tmp;

	if (!cmd || !shell)
		return (0);
	tmp = get_env_value("$PATH", shell);
	if (!tmp)
		return (0);
	*paths = ft_split(tmp, ':');
	free(tmp);
	if (!*paths)
		return (0);
	*args = ft_split(cmd, ' ');
	if (!*args)
		return (ft_free_tab(*paths), 0);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Search the good path for a cmd with the good method (not which xD)
char	*search_path(char *cmd, t_shell *shell)
{
	int		i;
	char	*tmp;
	char	*bin;
	char	**args;
	char	**paths;

	if (!init_path_search(cmd, shell, &paths, &args))
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		bin = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (!bin)
			break ;
		if (access(bin, F_OK | X_OK) == 0)
			return (ft_free_tab(paths), ft_free_tab(args), bin);
		free(bin);
	}
	return (ft_free_tab(paths), ft_free_tab(args), NULL);
}
