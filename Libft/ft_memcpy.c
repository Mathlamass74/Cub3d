/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:38:14 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:53:24 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n)
	{
		*ptr = *ptr2;
		n--;
		ptr++;
		ptr2++;
	}
	return (dst);
}
/*
int main() {
    char src[23] = "Ouais ! Ouais ! Ouais !";
    char dst[23];

    ft_memcpy(dst, src, 7);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    return 0;
}*/
