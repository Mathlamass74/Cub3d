/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:48:14 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:54:55 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((s1[i]) || (s2[i])) && (s1[i] == s2[i]) && (i < (n - 1)))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main()
{
    const char *str1 = "Hello";
    const char *str2 = "Hellz";
    int result = ft_strncmp(str1, str2, 5);

    if (result < 0)
        printf("str1 est inférieur à str2\n");
   	else if (result == 0)
        printf("str1 est égal à str2\n");
    else
        printf("str1 est supérieur à str2\n");
    return 0;
}*/
