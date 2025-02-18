/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:38:09 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/11 22:46:05 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// move memory area
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	if ((dst == NULL && src == NULL) && len != 0)
		return (NULL);
	temp_dst = (unsigned char *)dst;
	temp_src = (const unsigned char *)src;
	if (temp_dst < temp_src)
	{
		while (len--)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		temp_dst += len;
		temp_src += len;
		while (len--)
			*--temp_dst = *--temp_src;
	}
	return (dst);
}
