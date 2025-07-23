/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrasatry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:12:16 by vrasatry          #+#    #+#             */
/*   Updated: 2025/02/14 20:42:49 by vrasatry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_lst;
	t_list	*new_node;

	if (!lst || !del || !f)
		return (NULL);
	f_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&f_lst, del);
			return (NULL);
		}
		ft_lstadd_back (&f_lst, new_node);
		lst = lst->next;
	}
	return (f_lst);
}
