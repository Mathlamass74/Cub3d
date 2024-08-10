/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:58:04 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/06/27 10:56:06 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = start;
	j = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	cpy = (char *) malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	while (j < len && s[i])
		cpy[j++] = s[i++];
	cpy[j] = '\0';
	return (cpy);
}
/*
int main(void)
{
    char *str = "c'est pas la mairie zeubis ousi ousi";
    char *sub;

    sub = ft_substr(str, 23, 7);
    if (sub != NULL)
    {
        printf("Substring: %s\n", sub);
        free(sub);
	}
    return 0;
}
*/