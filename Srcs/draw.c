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

void	draw_dashed_line(t_data *d, int p_pos_x, int p_pos_y)
{
	int	err2;

	init_ray_params(d, p_pos_x, p_pos_y);
	while (p_pos_x != d->mouse_x || p_pos_y != d->mouse_y)
	{
		if (d->ray_p.dashed < DASH_LENGTH)
			mlx_pixel_put(d->mlx, d->win, p_pos_x, p_pos_y, YELLOW);
		d->ray_p.dashed = (d->ray_p.dashed + 1) % (2 * DASH_LENGTH);
		err2 = 2 * d->ray_p.draw_err;
		if (err2 > -d->ray_p.dif_abs_y)
		{
			d->ray_p.draw_err -= d->ray_p.dif_abs_y;
			p_pos_x += d->ray_p.step_x;
		}
		if (err2 < d->ray_p.dif_abs_x)
		{
			d->ray_p.draw_err += d->ray_p.dif_abs_x;
			p_pos_y += d->ray_p.step_y;
		}
	}
}

void	draw_player(t_data *d, double pos_x, double pos_y)
{
	int	start_x;
	int	start_y;
	int	x;
	int	y;

	start_x = (int)pos_x - PLAYER_SIZE / 2;
	start_y = (int)pos_y - PLAYER_SIZE / 2;
	x = start_x;
	while (x < start_x + PLAYER_SIZE)
	{
		y = start_y;
		while (y < start_y + PLAYER_SIZE)
		{
			mlx_pixel_put(d->mlx, d->win, x, y, RED);
			y++;
		}
		x++;
	}
}