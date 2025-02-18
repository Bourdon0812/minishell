/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:50:24 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 12:27:48 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/////////////////////////////////////////////////////////////////////////////
// Allocates memory for an array and initializes it to zero
void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total_size;
	size_t	i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size >= 4611686014132420609 / count)
		return (NULL);
	total_size = count * size;
	if (total_size / size != count)
		return (NULL);
	result = malloc(total_size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)result)[i] = 0;
		i++;
	}
	return ((void *)result);
}
