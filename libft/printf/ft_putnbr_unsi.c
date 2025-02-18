/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:36:18 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/15 15:27:01 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/////////////////////////////////////////////////////////////////////////////
// print unsigned nb on selected fd
void	ft_putnbr_unsi(unsigned int n, int fd)
{
	char			n_print;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n / 10 != 0)
		ft_putnbr_unsi(n / 10, fd);
	n_print = (n % 10) + '0';
	write(fd, &n_print, 1);
}
