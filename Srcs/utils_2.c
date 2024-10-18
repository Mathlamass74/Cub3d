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
		if (button == MOUSE_LEFT_BUTTON)
			d->map[(int)front_y][(int)front_x] = 'O';
	}
	return (0);
}
