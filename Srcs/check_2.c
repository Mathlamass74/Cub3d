#include "../Includes/cub3d.h"

double	check_cross_door_is_valid_move(t_data *d, double step, int option)
{
	double	pos_x;
	double	pos_y;

	pos_x = d->player.posx;
	pos_y = d->player.posy;
	d->cross_door = 0;
	if (option == 0)
	{
		if (d->map[(int)(pos_y + sin(d->player.player_angle) * step)]
		[(int)(pos_x + cos(d->player.player_angle) * step)] != '0')
			return (0);
	}
	else if (option == 1)
	{
		if (d->map[(int)(pos_y - sin(d->player.player_angle) * step)]
		[(int)(pos_x - cos(d->player.player_angle) * step)] != '0')
			return (0);
	}
	else
		return (0);
	return (step);
}
