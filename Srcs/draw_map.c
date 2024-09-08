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
