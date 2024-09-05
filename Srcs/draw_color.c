#include "../Includes/cub3d.h"

void	draw_circle(t_data *data, int x_center, int y_center, int color)
{
	int	x;
	int	y;
	int	x_pos;
	int	y_pos;
	int	dist_squared;

	x = -CIRCLE_RADIUS;
	while (x <= CIRCLE_RADIUS)
	{
		y = -CIRCLE_RADIUS;
		while (y <= CIRCLE_RADIUS)
		{
			dist_squared = x * x + y * y;
			if (dist_squared <= CIRCLE_RADIUS * CIRCLE_RADIUS)
			{
				x_pos = x_center + x;
				y_pos = y_center + y;
				if (x_pos >= 0 && x_pos < WIN_WIDTH && y_pos >= 0
					&& y_pos < WIN_HEIGHT)
					mlx_pixel_put(data->mlx, data->win, x_pos, y_pos, color);
			}
			y++;
		}
		x++;
	}
}

void	draw_color_picker(t_data *d)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	d->color_win = mlx_new_window(d->mlx, COLOR_WINDOW_WIDTH,
			COLOR_WINDOW_HEIGHT, "Pick Color");
	while (i < COLOR_WINDOW_WIDTH)
	{
		j = 0;
		while (j < COLOR_WINDOW_HEIGHT)
		{
			color = (i * 255 / COLOR_WINDOW_WIDTH) << 16
				| (j * 255 / COLOR_WINDOW_HEIGHT) << 8;
			mlx_pixel_put(d->mlx, d->color_win, i, j, color);
			j++;
		}
		i++;
	}
}

int	color_picker_click(int button, int x, int y, t_data *d)
{
	int	color;

	if (button == 1)
	{
		if (x >= 0 && x < COLOR_WINDOW_WIDTH && y >= 0
			&& y < COLOR_WINDOW_HEIGHT)
		{
			color = (x * 255 / COLOR_WINDOW_WIDTH) << 16
				| (y * 255 / COLOR_WINDOW_HEIGHT) << 8;
			d->draw_color = color;
			mlx_destroy_window(d->mlx, d->color_win);
			d->color_win = NULL;
		}
	}
	return (0);
}

int	close_color_window(int button, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		if (d->color_win)
		{
			mlx_destroy_window(d->mlx, d->color_win);
			d->color_win = NULL;
		}
	}
	return (0);
}
