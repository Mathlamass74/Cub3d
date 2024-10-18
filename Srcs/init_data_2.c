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

void	init_ray_params(t_data *d, double dir_x, double dir_y)
{
	d->ray.dif_abs_x = fabs(1 / dir_x);
	d->ray.dif_abs_y = fabs(1 / dir_y);
	if (dir_x < 0)
	{
		d->ray.step_x = -1;
		d->ray.dist_x = (d->player.posx - d->map_x) * d->ray.dif_abs_x;
	}
	else
	{
		d->ray.step_x = 1;
		d->ray.dist_x = (d->map_x + 1.0 - d->player.posx) * d->ray.dif_abs_x;
	}
	if (dir_y < 0)
	{
		d->ray.step_y = -1;
		d->ray.dist_y = (d->player.posy - d->map_y) * d->ray.dif_abs_y;
	}
	else
	{
		d->ray.step_y = 1;
		d->ray.dist_y = (d->map_y + 1.0 - d->player.posy) * d->ray.dif_abs_y;
	}
}

void	init_texture(t_text *texture)
{
	texture->text_ptr = NULL;
	texture->addr = NULL;
	texture->height = 0;
	texture->width = 0;
	texture->line_length = 0;
	texture->bits_per_pixel = 0;
	texture->tex_x = 0;
	texture->tex_y = 0;
}

void	init_textures(t_data *d)
{
	init_texture(&d->north_texture);
	init_texture(&d->south_texture);
	init_texture(&d->east_texture);
	init_texture(&d->west_texture);
	init_texture(&d->door_c_text);
	init_texture(&d->door_o_text);
	init_texture(&d->zizi_texture);
	d->door_c_path = ft_strdup("textures/Door-close.xpm");
	d->door_o_path = ft_strdup("textures/door_open.xpm");
	d->zizi_path = ft_strdup("textures/Teub.xpm");
}
