/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:12:28 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:50:53 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (s);
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
	ft_bzero(num, 5 *sizeof(int));
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
