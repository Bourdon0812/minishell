/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:27:29 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/11 22:44:48 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// Finds the first occurrence of a substring 
char	*is_in(const char *haystack, const char *needle, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (needle[j] && haystack[i] && i < len)
	{
		if (haystack[i] != needle[j])
			return (NULL);
		j++;
		i++;
	}
	if (needle[j] == '\0')
		return ((char *)&haystack[i - j]);
	return ((char *)&haystack[i - j]);
}

/////////////////////////////////////////////////////////////////////////////
// Finds the first occurrence of needle in haystack within len characters.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (i + needle_len <= len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (is_in(haystack, needle, i, len) != NULL)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
