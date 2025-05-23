/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:42:11 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/04/11 16:50:03 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*allocate_result(char *str)
{
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	*rm_quotes(char *str)
{
	int		i;
	int		j;
	char	quote;
	char	*result;

	result = allocate_result(str);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				result[j++] = str[i++];
			if (str[i])
				i++;
		}
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

int	skip_n_flags(char **args, int *newline_flag)
{
	int	i;
	int	j;

	i = 1;
	*newline_flag = 1;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		j = 1;
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		*newline_flag = 0;
		i++;
	}
	return (i);
}

void	expand_env_variable(const char *arg, int *i, int start, t_shell *shell)
{
	char	*name;
	char	*with_dollar;
	char	*value;

	if (start == *i)
	{
		write(1, "$", 1);
		return ;
	}
	name = ft_substr(arg, start, *i - start);
	with_dollar = ft_strjoin("$", name);
	free(name);
	value = get_env_value(with_dollar, shell);
	free(with_dollar);
	if (value)
	{
		write(1, value, ft_strlen(value));
		free(value);
	}
}
