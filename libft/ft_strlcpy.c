/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:17:46 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 17:40:57 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///////////////////////////////////////////////////////////////////
// copy str from src to dest with a fixed size
size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(src);
	if (dst_size == 0)
		return (l);
	while (src[i] != '\0' && i < dst_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (dst_size > 0)
	{
		dest[i] = '\0';
	}
	return (l);
}
