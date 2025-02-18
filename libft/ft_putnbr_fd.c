/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:44:13 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 12:51:02 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/////////////////////////////////////////////////////////////////////////////
// print nb on selected fd
void	ft_putnbr_fd(int n, int fd)
{
	char	n_print;
	long	num;

	num = (long)n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (num / 10 != 0)
		ft_putnbr_fd(num / 10, fd);
	n_print = (num % 10) + '0';
	write(fd, &n_print, 1);
}
