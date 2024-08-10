/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:05:56 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:35:22 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static int	ft_countnb(long int nb)
{
	size_t	counter;

	counter = 0;
	if (nb < 0)
	{
		counter++;
		nb *= -1;
	}
	if (nb >= -9 && nb <= 9)
		counter++;
	else
	{
		while (nb > 0)
		{
			nb /= 10;
			counter++;
		}
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	size_t			i;
	long int		nb;

	i = ft_countnb(n);
	nb = n;
	if (n < 0)
		nb *= -1;
	itoa = (char *) malloc(sizeof(char) * ft_countnb(n) + 1);
	if (itoa == NULL)
		return (NULL);
	itoa[i] = '\0';
	i--;
	if (n == 0)
		itoa[0] = '0';
	while (nb > 0)
	{
		itoa[i] = (nb % 10) + '0';
		i--;
		nb /= 10;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
/*
int	main(void)
{
	int	nb;

	nb = -2147483648;
	printf ("%s\n", ft_itoa(nb));
	return (0);
}*/
