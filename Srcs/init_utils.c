
#include "../Includes/cub3d.h"

// On copie la map dans le data->file grace à GNL
char	**file_cpy(char *path)
{
	int		fd;
	char	*line;
	char	**file;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(exit_game(0, NULL));
	file = malloc(sizeof(char *) * 1000);
	if (!file)
		exit(exit_game(1, NULL));
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
	return (start_y);
}

void	
