/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:34:11 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 18:43:41 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// add new link at the and of the lst
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}
