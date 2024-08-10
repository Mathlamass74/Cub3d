/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:59:13 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:35:09 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	totalsize;

	totalsize = count * size;
	if ((size != 0 && totalsize / size != count)
		|| (totalsize == 4611686014132420609))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int main()
{
	int *arr;
	int size = -2147483648;
	int i = 0;

	arr = (int*) ft_calloc(size, -2147483648);

	if (arr == NULL)
	{
		printf("Erreur d'allocation de mémoire.\n");
		return 1;
	}
	while (i < size)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return 0;
}*/