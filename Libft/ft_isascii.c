/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:10:19 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 18:51:46 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int main ()
{
	int a;
	int result;

	a = 'a';
	result = ft_isascii(a);
	printf ("le resultat est : %d\n", result);
	return (0);
}*/
