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
			printf("LA\n");
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
		message("The ESC key pressed.\n", 2, d);
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

int	mouse_move(int x, int y, t_data *d)
{
	d->mouse_x = x;
	d->mouse_y = y;
	mlx_clear_window(d->mlx, d->win);
	mlx_clear_window(d->minim.minimap_mlx, d->minim.minimap_win);
	draw_map(d);
	draw_minimap(d);
	draw_dashed_line(d, d->player.posx, d->player.posy);
	draw_player(d, d->player.posx, d->player.posy);
	return (0);
}
