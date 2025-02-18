/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:30:31 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/11 09:54:47 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// copy memory area
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (((unsigned char *)dst) == NULL && ((unsigned char *)src) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
