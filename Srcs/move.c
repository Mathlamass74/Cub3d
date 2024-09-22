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

bool	is_colision(t_data *d, double pos_x, double pos_y)
{
	int	x;
	int	y;

	x = (pos_x - TILE_SIZE / 2) / TILE_SIZE;
	y = (pos_y - TILE_SIZE / 2) / TILE_SIZE;
	if (d->map[y][x] == '0' || (d->map[y][x] == '2' && d->door == 1))
	{
		if (d->move == 0)
		{
			x = (d->player.posx - TILE_SIZE / 2) / TILE_SIZE;
			y = (d->player.posy - TILE_SIZE / 2) / TILE_SIZE;
			d->map[y][x] = '0';
		}
		if (d->map[y][x] == '2' && d->door == 1 && nxto(d))
		{
			if (d->move == d->move_check)
				d->open = 1;
			d->door = 0;
		}
		return (true);
	}
	else
		return (false);
}

int	deal_key(int key, t_data *d)
{
	double	new_player_x;
	double	new_player_y;

	if (key == 53)
		message("The ESC key pressed.\n", 2, d); // update?: return?
	new_player_y = y_move(key, d->player.posy);
	new_player_x = x_move(key, d->player.posx);
	check_door(d, key, new_player_x, new_player_y);
	if (key == 31)
		d->move_check = d->move;
	if (d->move != d->move_check)
		d->door = 0;
	if (is_colision(d, new_player_x, new_player_y))
	{
		if (d->open == 1 && d->move == d->move_check)
		{
			d->open = 0;
			new_player_y = y_move(key, new_player_y);
			new_player_x = x_move(key, new_player_x);
		}
		d->player.posx = new_player_x;
		d->player.posy = new_player_y;
	}
	which_key(key, d);
	return (0);
}

int	mouse_move(int x, int y, t_data *d) // dirx calculation updated
{
	int	delta_x;

	(void)y;
	delta_x = x - (WIN_WIDTH / 2);
	d->player.player_angle += delta_x * (M_PI / 180) * MOUSE_SENSITIVITY;
	if (d->player.player_angle < 0)
		d->player.player_angle += 2 * M_PI;
	else if (d->player.player_angle > 2 * M_PI)
		d->player.player_angle -= 2 * M_PI;
	d->player.dirx = cos(d->player.player_angle);
	d->player.diry = sin(d->player.player_angle);
	mlx_clear_window(d->mlx, d->win);
	draw_multiple_rays(d, d->player.posx, d->player.posy);
	draw_minimap(d);
	return (0);
}
