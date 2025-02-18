/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:18 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 18:30:20 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*result;
	t_list	*new_link;
	void	*new_element;	

	result = NULL;
	while (lst != NULL)
	{
		new_element = f(lst->content);
		if (new_element == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		new_link = ft_lstnew(new_element);
		if (new_link == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_link);
		lst = lst->next;
	}
	return (result);
}
