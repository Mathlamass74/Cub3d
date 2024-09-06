/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:41:44 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:54:59 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while ((haystack[i]) && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (needle[j]) && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char	str1[30] = "aaabcabcd";
	char	str2[10] = "aabc";

	printf ("Result : %s\n", ft_strnstr(str1, "cd", 9));
	return (0);
}*/