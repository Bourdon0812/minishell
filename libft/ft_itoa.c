/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:59:36 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 19:36:48 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
// count nomber of required char for print int
int	count_digits(int n)
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
		n /= 10;
		count++;
	}
	return (count);
}

/////////////////////////////////////////////////////////////////////////////
// convert integer into str
char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	num;

	num = n;
	len = count_digits(num);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		return (result[0] = '0', result);
	if (num < 0)
	{
		num = -num;
		result[0] = ('-');
	}
	while (num != 0)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
	printf("test : %s", ft_itoa(0));
	return (0);
} */