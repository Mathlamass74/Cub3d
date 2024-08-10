/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:10:30 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:56:08 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

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
