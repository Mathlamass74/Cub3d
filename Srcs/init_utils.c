/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:55:00 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/08/10 14:09:09 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// On copie la map dans le data->file grace à GNL
char **file_cpy(char *path)
{
	int		fd;
	char	*line;
	char	**file;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(exit_game(0));
	file = malloc(sizeof(char *) * 1000);
	if (!file)
		exit(exit_game(1));
	line = get_next_line(fd);
	file[i++] = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		file[i] = ft_strdup(line);
		i++;
	}
	file[i] = ft_strdup(line);
	free(line);
	close(fd);
	return (file);
}
