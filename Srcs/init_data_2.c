#include "../Includes/cub3d.h"

void	init_ray(t_ray_params *r)
{
	r->dif_abs_x = 0;
	r->dif_abs_y = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->draw_err = 0;
	r->dashed = 0;
}

void	init_ray_params(t_data *d, double p_pos_x, double p_pos_y, t_target *t)
{
	if (t->target_x - p_pos_x < 0)
		d->ray_p.dif_abs_x = (t->target_x - p_pos_x) * -1;
	else
		d->ray_p.dif_abs_x = t->target_x - p_pos_x;
	if (t->target_y - p_pos_y < 0)
		d->ray_p.dif_abs_y = (t->target_y - p_pos_y) * -1;
	else
		d->ray_p.dif_abs_y = t->target_y - p_pos_y;
	if (p_pos_x < t->target_x)
		d->ray_p.step_x = MOVE_STEP;
	else
		d->ray_p.step_x = -MOVE_STEP;
	if (p_pos_y < t->target_y)
		d->ray_p.step_y = MOVE_STEP;
	else
		d->ray_p.step_y = -MOVE_STEP;
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
	init_texture(&d->door_c_text);
	init_texture(&d->door_o_text);
	d->door_c_path = ft_strdup("textures/Door-close.xpm");
	d->door_o_path = ft_strdup("textures/door_open.xpm");
}

void	init_hit_position(t_data *d, t_target t)
{
	if (t.face == 'N' || t.face == 'S')
		d->hit_position = t.target_x - floor(t.target_x);
	else
		d->hit_position = t.target_y - floor(t.target_y);
}
