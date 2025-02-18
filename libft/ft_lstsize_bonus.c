/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:36:16 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 18:34:35 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// return the length of lst
int	ft_lstsize(t_list *lst)
{
	int		result;

	result = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		result++;
	}
	return (result);
}
