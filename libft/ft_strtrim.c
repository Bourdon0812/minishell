/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:47:03 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 12:28:34 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
// delete all char contained in set from the start and the end of s1
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	new_size;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	new_size = end - start;
	result = malloc((new_size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[start], new_size + 1);
	return (result);
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("   xxx   xxx", " x"));
	return (0);
} */