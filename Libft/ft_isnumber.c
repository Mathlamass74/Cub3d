/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:57:31 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/31 12:06:23 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			continue ;
		else
			return (0);
	}
	return (1);
}
