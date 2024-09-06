#include "../Includes/cub3d.h"

int	draw_map(t_data *d)
{
	int	x;
	int	y;
	int	s;

	s = 64;
	y = -1;
	while (++y < d->map_rows)
	{
		x = -1;
		while (++x < d->map_lgcol)
		{
			if (d->map[y][x] == '0')
				mlx_put_image_to_window(d->mlx, d->win,
					d->north_texture.text_ptr, x * s, y * s);
			if (d->map[y][x] == '1')
				mlx_put_image_to_window(d->mlx, d->win,
					d->south_texture.text_ptr, x * s, y * s);
		}
	}
	return (0);
}

void	message(char *msg, int n, t_data *d)
{
	printf("%s", msg);
	printf("\033[0m""");
	if (n == 1)
	{
		mlx_destroy_window(d->mlx, d->win);
	}
	exit(0);
}

int	 deal_key(int key, t_data *d)
{
	if (key == 53)
	{
		d->window_closed = true;
		message("The ESC key pressed.\n", 1, d);
	}
	return (0);
}

int	close_window(t_data *d)
{
	d->window_closed = true;
	message("The window has been closed.\n", 1, d);
	return (0);
}
