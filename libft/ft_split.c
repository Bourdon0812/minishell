/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:15:04 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 19:09:03 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
// count number of word in s
size_t	nb_of_str(const char *s, char c)
{
	size_t	i;
	int		result;
	int		is_on_word;

	i = 0;
	result = 0;
	is_on_word = 0;
	while (s[i])
	{
		if (s[i] != c && is_on_word == 0)
		{
			is_on_word = 1;
			result++;
		}
		else if (s[i] == c)
			is_on_word = 0;
		i++;
	}
	return (result);
}

/////////////////////////////////////////////////////////////////////////////
// duplicate str in memory with n and return pointer to the copy
char	*ft_strndup(const char *s1, size_t n)
{
	char		*tab;
	size_t		i;

	i = 0;
	tab = malloc(sizeof(char) * (n + 1));
	if (!tab)
		return (NULL);
	while (s1[i] && i < n)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/////////////////////////////////////////////////////////////////////////////
// split a str in tab of str with c
char	**ft_split(const char *s, char c)
{
	char		**result;
	size_t		i_j_k[3];

	i_j_k[0] = 0;
	i_j_k[1] = 0;
	i_j_k[2] = 0;
	result = malloc(sizeof(char *) * (nb_of_str(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i_j_k[0]])
	{
		while (s[i_j_k[0]] && s[i_j_k[0]] == c)
			i_j_k[0]++;
		i_j_k[1] = i_j_k[0];
		while (s[i_j_k[0]] && s[i_j_k[0]] != c)
			i_j_k[0]++;
		if (i_j_k[0] > i_j_k[1])
		{
			result[i_j_k[2]] = ft_strndup(&s[i_j_k[1]], i_j_k[0] - i_j_k[1]);
			i_j_k[2]++;
		}
	}
	result[i_j_k[2]] = NULL;
	return (result);
}
