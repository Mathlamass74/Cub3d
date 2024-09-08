#include "../Includes/cub3d.h"

double	y_move(int key, double pos)
{
	if (key == 13)
		return (pos - 64);
	else if (key == 1)
		return (pos + 64);
	return (pos);
}

double	x_move(int key, double pos)
{
	if (key == 0)
		return (pos - 64);
	else if (key == 2)
		return (pos + 64);
	return (pos);
}

int	deal_key(int key, t_data *d)
{
	double	new_player_x;
	double	new_player_y;

	if (key == 53)
	{
		d->window_closed = true;
		message("The ESC key pressed.\n", 1, d);
	}
	new_player_y = y_move(key, d->player.posy);
	new_player_x = x_move(key, d->player.posx);
	d->player.posx = new_player_x;
	d->player.posy = new_player_y;
	return (0);
}

int	mouse_move(int x, int y, t_data *d)
{
	d->mouse_x = x;
	d->mouse_y = y;
	mlx_clear_window(d->mlx, d->win);
	mlx_clear_window(d->minim.minimap_mlx, d->minim.minimap_win);
	draw_map(d);
	draw_minimap(d);
	draw_dashed_line(d, d->player.posx, d->player.posy);
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
