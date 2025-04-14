/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:51:51 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/14 02:02:32 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	start_exp(int i, t_shell *shell, char **args)
{
	int	in;

	in = var_is_in(shell->envp, args[i]);
	if (in >= 0)
		update_var(in, shell->envp, args[i]);
	else
		add_var(shell, args[i]);
}

void	handle_invalid_export(char *arg, char *original)
{
	ft_printf("Minishell: export: ");
	ft_printf("%s : not a valid identifier\n", arg);
	if (arg != original)
		free(arg);
}

char	*handle_missing_equal(char *arg)
{
	char	*temp;

	temp = ft_strjoin(arg, "=''");
	if (!temp)
		return (NULL);
	free(arg);
	return (temp);
}

int	exe_export(t_shell *shell, char **args)
{
	int		i;
	char	*original;

	i = 1;
	print_env(shell);
	while (args[i])
	{
		original = args[i];
		if (!ft_strchr(args[i], '='))
		{
			args[i] = handle_missing_equal(args[i]);
			if (!args[i])
				return (1);
		}
		if (!is_valid_varname(args[i]))
			handle_invalid_export(args[i], original);
		else
			start_exp(i, shell, args);
		i++;
	}
	return (0);
}
