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
		d->ray_p.step_x = 1.0;
	else
		d->ray_p.step_x = -1.0;
	if (p_pos_y < target->target_y)
		d->ray_p.step_y = 1.0;
	else
		d->ray_p.step_y = -1.0;
	d->ray_p.draw_err = d->ray_p.dif_abs_x - d->ray_p.dif_abs_y;
}

void	init_texture(t_text *texture)
{
	texture->text_ptr = NULL;
	texture->addr = NULL;
	texture->height = 0;
	texture->width = 0;
	texture->line_length = 0;
	texture->bits_per_pixel = 0;
}

void	init_textures(t_data *d)
{
	init_texture(&d->north_texture);
	init_texture(&d->south_texture);
	init_texture(&d->east_texture);
	init_texture(&d->west_texture);
}

void	init_dda(t_data *d, t_dda *dda)
{
	dda->map_pos_x = d->player.posx / 64;
	dda->map_pos_y = d->player.posy / 64;
	dda->side_dist_x = 0;
	dda->side_dist_y = 0;
	dda->delta_dist_x = 0;
	dda->delta_dist_y = 0;
	dda->ray_angle = 0;
	dda->ray_dir_x = 0;
	dda->ray_dir_y = 0;
}
