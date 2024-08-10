/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:49:29 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:56:03 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static int	ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		en;
	int		i;
	char	*s1trim;

	st = 0;
	en = ft_strlen(s1);
	i = 0;
	while ((s1[st]) && ft_check(s1[st], set) == 1)
		st++;
	while ((en > st) && ft_check(s1[en - 1], set) == 1)
		en--;
	s1trim = (char *) malloc(sizeof(char) * ((en - st) + 1));
	if (s1trim == NULL)
		return (NULL);
	while (st < en)
	{
		s1trim[i] = s1[st];
		i++;
		st++;
	}
	s1trim[i] = '\0';
	return (s1trim);
}
/*
int	main(void)
{
	char s1[] = "lorem ipsum dolor sit amet";
	printf ("Reulutat: %s\n", ft_strtrim(s1, "te"));
	return (0);
}*/