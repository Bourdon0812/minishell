/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:34:34 by ilbonnev          #+#    #+#             */
/*   Updated: 2025/03/04 17:06:29 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	has_unclosed_quotes(char *str)
{
	int	i;
	int	single_quote;
	int	double_quote;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && double_quote == 0)
			single_quote ^= 1;
		else if (str[i] == '"' && single_quote == 0)
			double_quote ^= 1;
		i++;
	}
	return (single_quote || double_quote);
}

void	skip_quotes_and_copy(char *str, char *nstr, int *i, int *i2)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] != '\0' && str[*i] != quote)
	{
		nstr[*i2] = str[*i];
		(*i)++;
		(*i2)++;
	}
	if (str[*i] == quote)
		(*i)++;
}

char	*remove_quotes(char *str)
{
	int		i;
	int		i2;
	int		len;
	char	*nstr;

	if (has_unclosed_quotes(str))
		return (ft_putstr_fd("Error: Unclosed quotes\n", 2), NULL);
	len = ft_strlen(str);
	i = 0;
	i2 = 0;
	nstr = malloc(sizeof(char) * (len + 1));
	if (nstr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (is_quote(str[i]))
			skip_quotes_and_copy(str, nstr, &i, &i2);
		else
			nstr[i2++] = str[i++];
	}
	nstr[i2] = '\0';
	return (nstr);
}

void	skip_quotes(char *input, int *i, char quote)
{
	(*i)++;
	while (input[*i] != quote && input[*i] != '\0')
		(*i)++;
	if (input[*i] == quote)
		(*i)++;
}
