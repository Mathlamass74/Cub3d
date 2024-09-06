/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:14 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:54:16 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
/*
void	ft_test(unsigned int i, char *s)
{
	write (1, &s[i], 1);
	write (1, "\n", 1);
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char *str = "Bah ouais mon ami";
	ft_striteri(str, ft_test);
	return (0);
}*/
