#include "../Includes/cub3d.h"

int	is_possible_move(t_data *d, double move_angle, double step)
{
	int	new_y;
	int	new_x;

	new_y = (int)((d->player.posy + (sin(move_angle) * step)));
	new_x = (int)((d->player.posx + (cos(move_angle) * step)));
	return (!check_is_wall(d, new_y, new_x));
}
