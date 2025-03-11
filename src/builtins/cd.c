/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:40 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/10 15:50:16 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <limits.h>

void	exe_cd(t_shell *shell)
{
	char *home = getenv("HOME");
    char *oldpwd = getenv("OLDPWD");
	char *pwd = getenv("PWD");
    char cwd[1024];

    ft_printf("%s\n%s\n", pwd, home);
}
