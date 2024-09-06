/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:10:30 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:55:18 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
int main(int ac, char **av)
{
	int	i = 1;

	if (ac > 1)
	{
		while (i < ac)
		{
			printf("%c -> %c\n", av[i][0], ft_tolower(av[i][0]));
			i++;
		}
	}
	return (0);
}*/
