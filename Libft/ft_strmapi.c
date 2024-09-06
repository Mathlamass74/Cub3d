/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:26:49 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/06 10:01:10 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

/*static char	ft_test(unsigned int i, char c)
{
	i = 32;
	if (c >= 'A' && c <= 'Z')
		c = c + i;
	else if (c >= 'a' && c <= 'z')
		c = c - i;
	return (c);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*str = "Bah ouais mon ami";

	printf ("Chaine avant : %s\n", str);
	printf ("Chaine apres : %s\n", ft_strmapi(str, ft_test));
	return (0);
}*/
