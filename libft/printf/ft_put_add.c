/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:30:49 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/19 16:25:49 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/////////////////////////////////////////////////////////////////////////////
// convert a pointer into an str with format -> 0x...
int	ft_put_add(void	*pointer, int fd)
{
	char			*temp;
	unsigned long	i;

	if (!pointer)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	temp = ft_itoa_plus((unsigned long)pointer, "0123456789abcdef");
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	i = 0;
	while (temp[i])
	{
		ft_putchar_fd(temp[i], fd);
		i++;
	}
	free(temp);
	return (i + 2);
}
