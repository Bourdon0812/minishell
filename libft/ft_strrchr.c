/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:36 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/11 22:43:00 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// Locates the last occurrence of a character in a string
char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	if ((char)c == '\0')
		return ((char *)&s[i + 1]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
