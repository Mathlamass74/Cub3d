#include "../Includes/cub3d.h"

int	y_move(int key, t_data *d)
{
	if (key == 13)
	{
		d->player.posx += cos(d->player.player_angle) * MOVE_STEP;
		d->player.posy += sin(d->player.player_angle) * MOVE_STEP;
		return (1);
	}
	else if (key == 1)
	{
		d->player.posx -= cos(d->player.player_angle) * MOVE_STEP;
		d->player.posy -= sin(d->player.player_angle) * MOVE_STEP;
		return (1);
	}
	return (0);
}

int	x_move(int key, t_data *d)
{
	if (key == 0)
	{
		d->player.posx += sin(d->player.player_angle) * MOVE_STEP;
		d->player.posy -= cos(d->player.player_angle) * MOVE_STEP;
		return (1);
	}
	else if (key == 2)
	{
		d->player.posx -= sin(d->player.player_angle) * MOVE_STEP;
		d->player.posy += cos(d->player.player_angle) * MOVE_STEP;
		return (1);
	}
	return (0);
}

int	deal_key(int key, t_data *d)
{
	if (key == LEFT_ARROW || key == RIGHT_ARROW)
        arrow_move(key, d);
	if (d->move == 0)
	{
		d->check_case.target_x = d->player.posx;
		d->check_case.target_y = d->player.posy;
	}
	if (d->player.posx / TILE_SIZE != d->check_case.target_x / TILE_SIZE)
		d->map[d->check_case.target_y / TILE_SIZE]
			[d->check_case.target_x / TILE_SIZE] = '0';
	if (key == 53)
		message("The ESC key pressed.\n", 2, d);
	if (y_move(key, d))
		d->move++;
	if (x_move(key, d))
		d->move++;
	return (0);
}

int	mouse_move(int x, int y, t_data *d)
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
	return (0);
}
