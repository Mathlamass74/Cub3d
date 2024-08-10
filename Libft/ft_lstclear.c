/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:53:05 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:54:54 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (del == NULL)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		temp = (*lst);
		(*lst) = (*lst)->next;
		free(temp);
	}
	(*lst) = NULL;
}
