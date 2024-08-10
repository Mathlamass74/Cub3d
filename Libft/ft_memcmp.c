/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:27:26 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:55:14 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*p1;
	unsigned const char	*p2;

	p1 = (unsigned const char *)s1;
	p2 = (unsigned const char *)s2;
	while (n)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	const char	str1[] = "Hello, world!";
	const char	str2[] = "Hello, World!";
	size_t		n = 8;
	int 		result;

	result = ft_memcmp(str1, str2, n);
	if (result < 0)
		printf("Les %zu premiers octets de s1 sont inférieurs à ceux de s2.\n", n);
	else if (result == 0)
		printf("Les %zu premiers octets de s1 et s2 sont identiques.\n", n);
	else
		printf("Les %zu premiers octets de s1 sont supérieurs à ceux de s2.\n", n);
	return (0);
}*/
