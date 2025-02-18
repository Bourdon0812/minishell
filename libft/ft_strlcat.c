/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:13:15 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 17:41:20 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// copy src a the end of dst with a fixed size
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	src_size;
	size_t	real_dest_size;
	size_t	i;

	src_size = ft_strlen(src);
	real_dest_size = ft_strlen(dst);
	i = 0;
	if (dst_size <= real_dest_size)
		return (dst_size + src_size);
	while (src[i] != '\0' && real_dest_size + i < dst_size - 1)
	{
		dst[real_dest_size + i] = src[i];
		i++;
	}
	dst[real_dest_size + i] = '\0';
	return (real_dest_size + src_size);
}
