#include "../Includes/cub3d.h"

double	try_move(t_data *d, double move_angle)
{
	double	try;

	try = 0.0;
	while (try <= 0.04)
	{
		if (is_possible_move(d, move_angle, MOVE_STEP - try))
			return (try);
		try += 0.01;
	}
	return (-0.05);
}

int	y_move(int key, t_data *d)
{
	double	stepyx;
	double	step;

	step = MOVE_STEP;
	if (key == 13)
	{
		stepyx = try_move(d, d->player.player_angle);
		if (stepyx < 0)
			return (0);
		step = cross_door(d, step, 0);
		d->player.posx += cos(d->player.player_angle) * (step - stepyx);
		d->player.posy += sin(d->player.player_angle) * (step - stepyx);
		return (1);
	}
	else if (key == 1)
	{
		stepyx = try_move(d, d->player.player_angle + M_PI);
		if (stepyx < 0)
			return (0);
		step = cross_door(d, step, 1);
		d->player.posx -= cos(d->player.player_angle) * (step - stepyx);
		d->player.posy -= sin(d->player.player_angle) * (step - stepyx);
		return (1);
	}
	return (0);
}

int	x_move(int key, t_data *d)
{
	double	stepyx;
	double	step;

	step = MOVE_STEP;
	if (key == 0)
	{
		stepyx = try_move(d, d->player.player_angle - (M_PI / 2));
		if (stepyx < 0)
			return (0);
		step = cross_door(d, step, 2);
		d->player.posx += sin(d->player.player_angle) * (step - stepyx);
		d->player.posy -= cos(d->player.player_angle) * (step - stepyx);
		return (1);
	}
	else if (key == 2)
	{
		stepyx = try_move(d, d->player.player_angle + (M_PI / 2));
		if (stepyx < 0)
			return (0);
		step = cross_door(d, step, 3);
		d->player.posx -= sin(d->player.player_angle) * (step - stepyx);
		d->player.posy += cos(d->player.player_angle) * (step - stepyx);
		return (1);
	}
	return (0);
}

int	deal_key(int key, t_data *d)
{
	if (key == LEFT_ARROW || key == RIGHT_ARROW)
		arrow_move(key, d);
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
