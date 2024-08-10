/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:57:31 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:56:11 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
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
			printf("%c -> %c\n", av[i][0], ft_toupper(av[i][0]));
			i++;
		}
	}
	return (0);
}*/
