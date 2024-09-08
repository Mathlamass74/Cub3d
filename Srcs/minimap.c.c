#include "../Includes/cub3d.h"

int	get_map_color(t_data *data, int x, int y)
{
	int	map_value;

	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return (0);
	map_value = data->map[y][x];
	return (map_value);
}

void	draw_minimap(t_data *d)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		while (x < MINIMAP_WIDTH)
		{
			d->minim.map_x = x * (d->map_width / MINIMAP_WIDTH);
			d->minim.map_y = y * (d->map_height / MINIMAP_HEIGHT);
			color = get_map_color(d, d->minim.map_x, d->minim.map_y);
			mlx_pixel_put(d->minim.minimap_mlx, d->minim.minimap_win,
				d->minim.x + x, d->minim.y + y, color);
			x++;
		}
		y++;
	}
}

void	create_minimap_window(t_data *d)
{
	d->minim.minimap_mlx = mlx_init();
	d->minim.minimap_win = mlx_new_window(d->minim.minimap_mlx,
			MINIMAP_WIDTH, MINIMAP_HEIGHT, "Minimap");
}
