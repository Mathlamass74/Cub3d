
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

void	init_steps(t_data *d, double posx, double posy)
{
	if (d->dda.raydir_x < 0)
	{
		d->dda.step_x = -1.0;
		d->dda.sidedist_x = (posx - d->dda.mapx) * d->dda.deltadist_x;
	}
	else
	{
		d->dda.step_x = 1.0;
		d->dda.sidedist_x = (d->dda.mapx + 1.0 - posx) * d->dda.deltadist_x;
	}
	if (d->dda.raydir_y < 0)
	{
		d->dda.step_y = -1.0;
		d->dda.sidedist_y = (posy - d->dda.mapy) * d->dda.deltadist_y;
	}
	else
	{
		d->dda.step_y = 1.0;
		d->dda.sidedist_y = (d->dda.mapy + 1.0 - posy) * d->dda.deltadist_y;
	}
}

void	init_dda_params(t_data *d, double p_pos_x, double p_pos_y , int x)
{
	d->player.planex = d->player.diry * (FOV * 0.01);
	d->player.planey = -d->player.dirx * (FOV * 0.01);
	d->player.camerax = ((2 * x) / WIN_WIDTH) - 1;
	d->dda.raydir_x = \
		d->player.dirx * d->player.planex * d->player.camerax;
	d->dda.raydir_y = \
		d->player.diry * d->player.planey * d->player.camerax;
	d->dda.mapx = (int)p_pos_x;
	d->dda.mapy = (int)p_pos_y;
	if (d->dda.raydir_x == 0)
		d->dda.raydir_x = 1e30;
	if (d->dda.raydir_y == 0)
		d->dda.raydir_y = 1e30;
	d->dda.deltadist_x = fabs(1 / d->dda.raydir_x);
	d->dda.deltadist_y = fabs(1 / d->dda.raydir_y);
}

void	update_player_pos_in_map(t_data *d, int y, int x)
{
	d->map_char_counter++;
	d->player.dir = d->map[y][x];
	d->player.posx = x + 0.5;
	d->player.posy = y + 0.5;
	d->map[y][x] = '0';
}
