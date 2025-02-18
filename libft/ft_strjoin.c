/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:03:08 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 19:10:21 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
// combine two str in one
char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*result;
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
