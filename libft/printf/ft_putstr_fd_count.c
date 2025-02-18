/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:31:35 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/15 15:18:36 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/////////////////////////////////////////////////////////////////////////////
// print str on selected fd
int	ft_putstr_fd_count(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
