/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:13:00 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:55:07 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int main(void)
{
    t_list *new_node;
    char   *data = "Hello, world!";

    new_node = ft_lstnew(data);
    if (new_node == NULL)
    {
        printf("Failed to allocate memory for the new node.\n");
        return (1);
    }
    printf("Content of the new node: %s\n", (char *)new_node->content);
    free(new_node);
    return (0);
}*/