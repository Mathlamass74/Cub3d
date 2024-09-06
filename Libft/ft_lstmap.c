/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:33:32 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:52:55 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	list = NULL;
	if (!f || !del || !lst)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (temp == NULL)
		return (NULL);
	list = temp;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (temp->next == NULL)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		lst = lst->next;
		temp = temp->next;
	}
	temp->next = NULL;
	return (list);
}
