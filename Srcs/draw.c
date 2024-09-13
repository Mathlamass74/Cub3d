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
			if (d->map[y][x] == '2')
				mlx_put_image_to_window(d->mlx, d->win,
					d->east_texture.text_ptr, x * s, y * s);
		}
	}
	draw_minimap(d);
	return (0);
}

void	draw_dashed_line(t_data *d, int p_pos_x, int p_pos_y, double player_angle)
{
	double	ray_angle;
	int		err2;
	int		j = 0;
	int		x;
	int		y;
	int		stepsize = 1;

	x = p_pos_x;
	y = p_pos_y;
	while (j < 60)
	{
		init_ray_params(d, x, y);
		ray_angle =  player_angle - (j * FOV / 60 - (FOV / 2)) * (PI / 180);
		PI2("j", j);
		PF(ray_angle);
		while (d->map[y / TILE_SIZE][x / TILE_SIZE] == '0')
		{
			x += cos(ray_angle) * stepsize;
			y += sin(ray_angle) * stepsize;
			if (d->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
				break ;
			mlx_pixel_put(d->mlx, d->win, x, y, GREEN);
			err2 = 2 * d->ray_p.draw_err;
			if (err2 > -d->ray_p.dif_abs_y)
			{
				d->ray_p.draw_err -= d->ray_p.dif_abs_y;
				x += d->ray_p.step_x;
			}
			if (err2 < d->ray_p.dif_abs_x)
			{
				d->ray_p.draw_err += d->ray_p.dif_abs_x;
				y += d->ray_p.step_y;
			}
		}
		j++;
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
