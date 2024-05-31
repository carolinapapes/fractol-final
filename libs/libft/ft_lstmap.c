/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:09:19 by capapes           #+#    #+#             */
/*   Updated: 2024/01/31 22:25:48 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*add_node;

	if (!lst || !f || !del)
		return (0);
	new = NULL;
	while (lst)
	{
		temp = f(lst->content);
		add_node = ft_lstnew(temp);
		if (!add_node)
		{
			del(temp);
			ft_lstclear(&new, del);
			free(add_node);
			return (0);
		}
		ft_lstadd_back(&new, add_node);
		lst = lst->next;
	}
	return (new);
}
