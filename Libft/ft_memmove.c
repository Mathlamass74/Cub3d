/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:49:48 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:55:19 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr2 < ptr)
	{
		while (len--)
			ptr[len] = ptr2[len];
	}
	else
	{
		while (len--)
			*ptr++ = *ptr2++;
	}
	return (dst);
}
/*
int	main()
{
    char src[23] = "Ouais ! Ouais ! Ouais !";
    char dst[23];

    ft_memmove(dst, src, 23);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    return 0;
}*/
