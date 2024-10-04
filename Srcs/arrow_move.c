#include "../Includes/cub3d.h"

void	move_camera_left(t_data *d, double angle)
{
    d->player.player_angle += angle;
    if (d->player.player_angle > 2 * M_PI)
        d->player.player_angle -= 2 * M_PI;
    else if (d->player.player_angle < 0)
        d->player.player_angle += 2 * M_PI;
}

void	move_camera_right(t_data *d, double angle)
{
    d->player.player_angle += angle;
    if (d->player.player_angle > 2 * M_PI)
        d->player.player_angle -= 2 * M_PI;
    else if (d->player.player_angle < 0)
        d->player.player_angle += 2 * M_PI;
}

int	arrow_move(int key, t_data *d)
{
	d->player.dirx = cos(d->player.player_angle);
	d->player.diry = sin(d->player.player_angle);
	if (key == LEFT_ARROW)
		move_camera_left(d, -ROT_ANGLE);
	else if (key == RIGHT_ARROW)
		move_camera_right(d, ROT_ANGLE);
	// printf("Angle: %f\n", d->player.player_angle);
	return (0);
}
