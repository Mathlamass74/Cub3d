/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:15:57 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/06 09:51:56 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*f_strchr(char *s, int c);
char	*f_strjoin(char *s1, char *s2);
char	*f_strdup(char *s1);
int		ft_malloc_count(char *stock);

// char	*get_next_line(int fd);
// char	*read_line(int fd, char *stash);
// char	*ft_get_line(char *stash);
// char	*ft_get_new_line(char *stash);
// void	*ft_free(char **str);

#endif