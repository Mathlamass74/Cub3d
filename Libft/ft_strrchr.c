/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:32:47 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:55:03 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *) &s[i]);
	while (i != (size_t)-1)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
/*
int	main(void)
{
	const char	*str = "Bonjour le monde!";
	char		c = 'o';
	char		*result = ft_strrchr(str, c);

	if (result)
		printf("Le caractère '%c' a été trouvé à la pos %ld.\n", c, result - str);
	else
		printf("Le caractère '%c' n'a pas été trouvé.\n", c);
	return (0);
}*/
