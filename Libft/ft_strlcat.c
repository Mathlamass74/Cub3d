/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:26:36 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:54:34 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = 0;
	lsrc = 0;
	i = 0;
	while (src[lsrc] != '\0')
		lsrc++;
	if (dstsize == 0)
		return (lsrc);
	while (dst[ldst] != '\0' && ldst < dstsize)
		ldst++;
	if (dstsize <= ldst)
		return (dstsize + lsrc);
	while ((src[i]) && ((ldst + i) < (dstsize - 1)))
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (lsrc + ldst);
}
/*
int	main(void)
{
	char		dst[12] = "";
	const char	*src = "Ouais ouais ouais !";
	size_t		result = ft_strlcat(dst, src, sizeof(dst));

	printf("Résultat de ft_strlcat : %zu\n", result);
	printf ("dst apres ft_strlcat : %s\n", dst);
	return (0);
}*/
