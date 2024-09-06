/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:02:46 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:53:14 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	i = 0;
	str = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	str[] = "Hello, world!";
	char		c = 'w';
	char		*result = (char *)ft_memchr(str, c, sizeof(str));

	if (result)
		printf("Character '%c' found at position: %ld\n", c, result - str);
	else
		printf("Character '%c' not found in the string.\n", c);
	return (0);
}*/
