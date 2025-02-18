/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:57:52 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/04 14:53:49 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdlib.h>

char	*ft_itoa_plus(unsigned long n, char *base);
int		ft_printf(const char *str, ...);
int		ft_count_digits(int n, int base);
int		ft_count_digits_plus(unsigned int n);
int		ft_put_add(void	*pointer, int fd);
int		ft_putstr_fd_count(char *s, int fd);
int		ft_puthex_fd(unsigned int number, char *base);
void	ft_putnbr_unsi(unsigned int n, int fd);

#endif