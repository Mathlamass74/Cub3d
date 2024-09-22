
#include "../Includes/cub3d.h"

// On met à jour les directions du player en fonction de l'orientation

void	update_player_dir(t_data *d)
{
	if (d->player.dir == 'N')
	{
		d->player.diry = -1;
		d->player.dirx = 0;
		d->player.player_angle = 3 * M_PI / 2;
	}
	else if (d->player.dir == 'S')
	{
		d->player.diry = 1;
		d->player.dirx = 0;
		d->player.player_angle = M_PI / 2;
	}
	else if (d->player.dir == 'E')
	{
		d->player.dirx = 1;
		d->player.diry = 0;
		d->player.player_angle = 0;
	}
	else if (d->player.dir == 'W')
	{
		d->player.dirx = -1;
		d->player.diry = 0;
		d->player.player_angle = M_PI;
	}
}
