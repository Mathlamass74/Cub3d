/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:27:27 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:55:21 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	value;
	size_t			i;

	ptr = (unsigned char *)b;
	value = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = value;
		i++;
	}
	return (b);
}
/*
int	main()
{
	int	num[5] = {1, 2, 3, 4, 5};
	int	i = 0;
	printf("Before	: ");

	while (i < 5)
	{
		printf("%d", num[i]);
		i++;
	}
	printf("\n");
	ft_memset(num, 0, sizeof(num));
	printf("After	: ");

	i = 0;
	while (i < 5)
	{
		printf("%d", num[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
