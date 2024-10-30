/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 12:55:52 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	malloc_map_height(char ***file, char *path)
{
	int		fd;
	int		map_height;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(exit_game(0, NULL));
	line = get_next_line(fd);
	map_height = 2;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map_height++;
	}
	free(line);
	close(fd);
	*file = malloc(sizeof(char *) * map_height);
	if (!*file)
		exit(exit_game(1, NULL));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(exit_game(0, NULL));
	return (fd);
}

// On copie la map dans le data->file grace à GNL
char	**file_cpy(char *path)
{
	int		fd;
	char	*line;
	char	**file;
	int		i;

	i = 0;
	fd = malloc_map_height(&file, path);
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

void	init_image(t_data *d)
{
	d->img.img_ptr = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->img.addr = mlx_get_data_addr(d->img.img_ptr, &d->img.bits_per_pixel,
			&d->img.line_length, &d->img.endian);
}

int	init_wall_dimensions(double *start_y, double wall_height, t_target *t)
{
	*start_y = (WIN_HEIGHT / 2) - (wall_height / 2);
	if (*start_y < 0)
		*start_y = 0;
	t->end_y = (*start_y + wall_height);
	if (t->end_y >= WIN_HEIGHT)
		t->end_y = WIN_HEIGHT;
	return (*start_y);
}

void	init_texture_pos(t_data *d, t_target *t, double ray_angle)
{
	if (t->face == 'N' || t->face == 'S' || t->face == 'D')
		d->hit_pos = d->player.posy + d->ray_dist * sin(ray_angle);
	else
		d->hit_pos = d->player.posx + d->ray_dist * cos(ray_angle);
}
