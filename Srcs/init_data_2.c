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

void	init_ray_params(t_data *d, int p_pos_x, int p_pos_y)
{
	if (d->mouse_x - p_pos_x < 0)
		d->ray_p.dif_abs_x = (d->mouse_x - p_pos_x) * -1;
	else
		d->ray_p.dif_abs_x = d->mouse_x - p_pos_x;
	if (d->mouse_y - p_pos_y < 0)
		d->ray_p.dif_abs_y = (d->mouse_y - p_pos_y) * -1;
	else
		d->ray_p.dif_abs_y = d->mouse_y - p_pos_y;
	if (p_pos_x < d->mouse_x)
		d->ray_p.step_x = 1;
	else
		d->ray_p.step_x = -1;
	if (p_pos_y < d->mouse_y)
		d->ray_p.step_y = 1;
	else
		d->ray_p.step_y = -1;
	d->ray_p.draw_err = d->ray_p.dif_abs_x - d->ray_p.dif_abs_y;
}	

void	init_minimap(t_data *d)
{
	d->minim.minimap = NULL;
	d->minim.minimap_mlx = NULL;
	d->minim.minimap_win = NULL;
	d->minim.x = WIN_WIDTH - MINIMAP_WIDTH;
	d->minim.y = WIN_HEIGHT - MINIMAP_HEIGHT;
	d->minim.map_x = 0;
	d->minim.map_y = 0;
}
