/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:56:54 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 18:59:02 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
// clean one link and all next link
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_clean;

	while (*lst != NULL)
	{
		next_clean = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_clean;
	}
	*lst = NULL;
}
