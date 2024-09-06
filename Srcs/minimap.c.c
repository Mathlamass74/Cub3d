#include "../Includes/cub3d.h"

void	draw_dashed_line(t_data *d, int p_pos_x, int p_pos_y)
{
	init_ray_params(d, p_pos_x, p_pos_y);
	int e2;

	while (p_pos_x != d->mouse_x || p_pos_y != d->mouse_y)
	{
		if (d->ray_p.dashed < DASH_LENGTH)
			mlx_pixel_put(d->mlx, d->win, p_pos_x, p_pos_y, YELLOW);
		d->ray_p.dashed = (d->ray_p.dashed + 1) % (2 * DASH_LENGTH);
		e2 = 2 * d->ray_p.draw_err;
		if (e2 > -d->ray_p.dif_abs_y)
		{
			d->ray_p.draw_err -= d->ray_p.dif_abs_y;
			p_pos_x += d->ray_p.step_x;
		}
		if (e2 < d->ray_p.dif_abs_x)
		{
			d->ray_p.draw_err += d->ray_p.dif_abs_x;
			p_pos_y += d->ray_p.step_y;
		}
	}
}

// int get_map_color(t_data *data, int x, int y)
// {
// 	int map_value;

//     if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
//         return (0);
//     map_value = data->map[y][x];
//     return (map_value);
// }

void	draw_minimap(t_data *d)
{
	int	x;
	int	y;
	int color;

	x = 0;
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		while (x < MINIMAP_WIDTH)
		{
			d->minim.map_x = x * (d->map_width / MINIMAP_WIDTH);
			d->minim.map_y = y * (d->map_height / MINIMAP_HEIGHT);
			//color = get_map_color(d, d->minim.map_x, d->minim.map_y);
			//mlx_pixel_put(d->minim.minimap_mlx, d->minim.minimap_win, d->minim.x + x, d->minim.y + y, color);
			x++;
		}
		y++;
	}
}

void	create_minimap_window(t_data *d)
{
	d->minim.minimap_mlx = mlx_init();
	d->minim.minimap_win = mlx_new_window(d->minim.minimap_mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT, "Minimap");
}
