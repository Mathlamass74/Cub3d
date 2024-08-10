/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:13:31 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:54:56 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del == NULL)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
