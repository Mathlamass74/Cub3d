#include "../Includes/cub3d.h"

void	init_ray(t_ray_params *r)
{
	r->dif_abs_x = 0;
	r->dif_abs_y = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->draw_err = r->dif_abs_x - r->dif_abs_y;
	r->dashed = 0;
}

void	init_minimap(t_data *d)
{
	d->mm.minimap_x = 0;
	d->mm.minimap_y = 0;
	d->mm.player_x = d->mm.minimap_x
		+ (MINIMAP_SIZE / 2) - (PLAYER_SIZE / 2);
	d->mm.player_y = d->mm.minimap_y
		+ (MINIMAP_SIZE / 2) - (PLAYER_SIZE / 2);
	d->mm.map_x = 0;
	d->mm.map_y = 0;
	d->mm.scale = TILE_SIZE * MINIMAP_SCALE;
}

void	init_ray_params(t_data *d, int p_pos_x, int p_pos_y, t_target *target)
{
	if (target->target_x - p_pos_x < 0)
		d->ray_p.dif_abs_x = (target->target_x - p_pos_x) * -1;
	else
		d->ray_p.dif_abs_x = target->target_x - p_pos_x;
	if (target->target_y - p_pos_y < 0)
		d->ray_p.dif_abs_y = (target->target_y - p_pos_y) * -1;
	else
		d->ray_p.dif_abs_y = target->target_y - p_pos_y;
	if (p_pos_x < target->target_x)
		d->ray_p.step_x = 1;
	else
		d->ray_p.step_x = -1;
	if (p_pos_y < target->target_y)
		d->ray_p.step_y = 1;
	else
		d->ray_p.step_y = -1;
	d->ray_p.draw_err = d->ray_p.dif_abs_x - d->ray_p.dif_abs_y;
}
