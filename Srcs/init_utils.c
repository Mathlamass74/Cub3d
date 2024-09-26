
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
