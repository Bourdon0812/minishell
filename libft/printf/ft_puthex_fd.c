/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:49:10 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/19 16:27:28 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/////////////////////////////////////////////////////////////////////////////
// print unsigned int into hex
int	ft_puthex_fd(unsigned int number, char *base)
{
	char	*temp;
	int		i;

	temp = ft_itoa_plus(number, base);
	i = ft_putstr_fd_count(temp, 1);
	free(temp);
	return (i);
}
