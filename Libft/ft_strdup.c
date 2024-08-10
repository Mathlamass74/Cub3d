/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:05:11 by gsims             #+#    #+#             */
/*   Updated: 2024/06/27 13:08:01 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, i + 1);
	return (dest);
}
/*
int	main()
{
	char	*src = "hello tings";

	printf("source address : %p\n", &src);
	printf("dest address : %p\n", ft_strdup(src));	
	return (0);	
}*/
