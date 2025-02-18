/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:36 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/15 15:59:35 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "ft_printf.h"

/////////////////////////////////////////////////////////////////////////////
// selector for numbers section of printf
void	selector_numbers(const char **str, va_list *args, size_t *c)
{
	int	temp;

	if (**str == 'd')
		return (temp = (int)va_arg(*args, int),
			ft_putnbr_fd(temp, 1), (*c) += ft_count_digits(temp, 10),
			(*str)++, (void)0);
	else if (**str == 'i')
		return (temp = (int)va_arg(*args, int),
			ft_putnbr_fd(temp, 1), (*c) += ft_count_digits(temp, 10),
			(*str)++, (void)0);
	else if (**str == 'u')
		return (temp = (unsigned int)va_arg(*args, unsigned int),
			ft_putnbr_unsi(temp, 1), (*c) += ft_count_digits_plus(temp),
			(*str)++, (void)0);
}

/////////////////////////////////////////////////////////////////////////////
// other section of printf
void	selector(const char **str, va_list *args, size_t *c)
{
	if (**str == 'c')
		return (ft_putchar_fd((char)va_arg(*args, int), 1),
			(*str)++, (*c)++, (void)0);
	else if (**str == 's')
		return ((*c) += ft_putstr_fd_count((char *)va_arg(*args, char *), 1),
			(*str)++, (void)0);
	else if (**str == 'p')
		return ((*c) += ft_put_add((void *)va_arg(*args, char *), 1),
			(*str)++, (void)0);
	else if (**str == 'x')
		return ((*c) += ft_puthex_fd((unsigned int)va_arg(*args, unsigned int),
				"0123456789abcdef"), (*str)++, (void)0);
	else if (**str == 'X')
		return ((*c) += ft_puthex_fd((unsigned int)va_arg(*args, unsigned int),
				"0123456789ABCDEF"), (*str)++, (void)0);
	else if (**str == '%')
		return (ft_putchar_fd('%', 1), (*str)++, (*c)++, (void)0);
	else
		selector_numbers(str, args, c);
}

/////////////////////////////////////////////////////////////////////////////
// main printf function
int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			selector(&str, &args, &count);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
