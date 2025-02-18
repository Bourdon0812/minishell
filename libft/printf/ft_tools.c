/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:26:35 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/15 15:20:21 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/////////////////////////////////////////////////////////////////////////////
// count nomber of required char for print int
int	ft_count_digits(int n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

/////////////////////////////////////////////////////////////////////////////
// count nomber of required char for print unsigned long
int	ft_count_digits_plus(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/////////////////////////////////////////////////////////////////////////////
// count nomber of required char for print unsigned long
int	ft_count_digits_hex(unsigned long n)
{
	unsigned long	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

/////////////////////////////////////////////////////////////////////////////
// convert unsigned long into hex str 
char	*ft_itoa_plus(unsigned long n, char *base)
{
	char			*result;
	unsigned long	len;

	len = ft_count_digits_hex(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		return (result[0] = '0', result);
	while (n != 0)
	{
		result[--len] = base[(n % 16)];
		n /= 16;
	}
	return (result);
}
