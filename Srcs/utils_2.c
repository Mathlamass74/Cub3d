#include "../Includes/cub3d.h"

int	is_possible_move(t_data *d, double move_angle, double step)
{
	int	new_y;
	int	new_x;

	new_y = (int)((d->player.posy + (sin(move_angle) * step)));
	new_x = (int)((d->player.posx + (cos(move_angle) * step)));
	return (!check_is_wall(d, new_y, new_x));
}

int	is_door_at_position(double x, double y, t_data *d)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (d->map[map_y][map_x] == 'D' || d->map[map_y][map_x] == 'O')
		return (1);
	return (0);
}

int	mouse_click(int button, int x, int y, t_data *d)
{
	double	front_x;
	double	front_y;

	(void)x;
	(void)y;
	front_x = d->player.posx + cos(d->player.player_angle);
	front_y = d->player.posy + sin(d->player.player_angle);
	if (is_door_at_position(front_x, front_y, d))
	{
		if (button == MOUSE_LEFT_BUTTON && d->open == 0)
			d->open = 1;
		else if (button == MOUSE_LEFT_BUTTON && d->open == 1)
			d->open = 0;
		if (d->open == 1)
			d->map[(int)front_y][(int)front_x] = 'O';
		else if (d->open == 0)
			d->map[(int)front_y][(int)front_x] = 'D';
	}
	return (0);
}

double	cross_door_utils(t_data *d, double step, int option)
{
	double	pos_x;
	double	pos_y;

	pos_x = d->player.posx;
	pos_y = d->player.posy;
	if (option == 1)
	{
		while (d->map[(int)(pos_y - sin(d->player.player_angle) * step)]
			[(int)(pos_x - cos(d->player.player_angle) * step)] == 'O')
			step += 0.01;
	}
	else
		return (0);
	return (step);
}

double	cross_door(t_data *d, double step, int option)
{
	double	pos_x;
	double	pos_y;
	double	step2;

	pos_x = d->player.posx;
	pos_y = d->player.posy;
	step2 = step;
	if (d->cross_door == 1)
	{
		if (option == 0)
		{
			while (d->map[(int)(pos_y + sin(d->player.player_angle) * step)]
				[(int)(pos_x + cos(d->player.player_angle) * step)] == 'O')
				step += 0.01;
		}
		else
			step = cross_door_utils(d, step, option);
		step2 = check_cross_door_is_valid_move(d, step, option);
		return (step2);
	}
	else
		return (step2);
}
