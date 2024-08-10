/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:51:40 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:55:33 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static int	ft_c_count(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	*ft_strsplit(char const *s, char c, int *pi)
{
	char	*str;
	int		start;
	int		len;

	while (s[*pi] && s[*pi] == c)
		(*pi)++;
	start = *pi;
	while (s[*pi] && s[*pi] != c)
		(*pi)++;
	len = *pi - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		strs;

	i = 0;
	j = 0;
	strs = ft_c_count(s, c);
	tab = (char **) malloc(sizeof(char *) * (strs + 1));
	if (tab == NULL)
		return (NULL);
	while (j < strs)
	{
		tab[j] = ft_strsplit(s, c, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
/*
int	main(int ac, char **av)
{
	int		i;
	char	**result;

	i = 0;
	if (ac == 3)
	{
		**result = ft_split(av[1], av[2][0]);
		while (result[i] != NULL)
		{
			printf("%s\n", result[i]);
			i++;
		}
	}
	return (0);
}*/
