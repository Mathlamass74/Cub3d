/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:13:58 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:54:05 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *) &s[i]);
	return (0);
}
/*
int	main(void)
{
	const char	*str = "Bonjour le monde!";
	char		c = '\0';
	char		*result = ft_strchr(str, c);

	if (result)
		printf("Le caractère '%c' a été trouvé à la pos %ld.\n", c, result - str);
	else
		printf("Le caractère '%c' n'a pas été trouvé.\n", c);
	return (0);
}*/
