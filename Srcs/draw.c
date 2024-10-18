#include "../Includes/cub3d.h"

int	get_pixel_from_texture(t_text *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->addr
		+ (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

double	calcul_dist(t_data *d, t_target *target, double dir_x, double dir_y)
{
	double	side;

	d->map_x = (int)d->player.posx;
	d->map_y = (int)d->player.posy;
	d->hit = 0;
	init_ray_params(d, dir_x, dir_y);
	while (d->hit == 0)
	{
		side = set_face_side(d);
		if (d->map[d->map_y][d->map_x] != '0'
			&& d->map[d->map_y][d->map_x] != 'O'
			&& d->map[d->map_y][d->map_x] != 'C')
		{
			d->hit = 1;
			target->target_x = d->map_x;
			target->target_y = d->map_y;
			set_wall_face(d, target, side);
		}
	}
	if (side == 0)
		return ((d->map_x - d->player.posx + (1 - d->ray.step_x) / 2) / dir_x);
	else
		return ((d->map_y - d->player.posy + (1 - d->ray.step_y) / 2) / dir_y);
}

void	render_wall_slice(t_data *d, int ray_ind, t_target *t, double ray_angle)
{
	double	wall_height;
	double	start_y;
	t_text	*texture;
	int		i;

	texture = get_wall_texture(d, t);
	wall_height = WIN_HEIGHT / d->ray_dist;
	start_y = (WIN_HEIGHT / 2) - (wall_height / 2);
	if (start_y < 0)
		start_y = 0;
	t->end_y = (start_y + wall_height);
	if (t->end_y >= WIN_HEIGHT)
		t->end_y = WIN_HEIGHT;
	i = start_y;
	if (t->face == 'N' || t->face == 'S' || t->face == 'D')
		d->hit_pos = d->player.posy + d->ray_dist * sin(ray_angle);
	else
		d->hit_pos = d->player.posx + d->ray_dist * cos(ray_angle);
	texture->tex_x = (d->hit_pos - floor(d->hit_pos)) * texture->width;
	while (i++ < t->end_y)
	{
		texture->tex_y = ((i - start_y) * texture->height) / wall_height;
		if (d->file_ != NULL)
			fprintf(d->file_, "Ray Index: %d, tex_x: %d, tex_y: %d, ray_dist: %f\n", ray_ind, texture->tex_x, texture->tex_y, d->ray_dist);
		put_pixel_to_image(&d->img, ray_ind, i,
			get_pixel_from_texture(texture, texture->tex_x, texture->tex_y));
	}
}

void	draw_multiple_rays(t_data *d, double dir_x, double dir_y)
{
	int			i;
	double		ray_angle;
	double		angle_step;
	t_target	t;

	angle_step = FOV * M_PI / 180.0 / WIN_WIDTH;
	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_angle = d->player.player_angle - FOV * M_PI / 360 + i * angle_step;
		dir_x = cos(ray_angle);
		dir_y = sin(ray_angle);
		d->ray_dist = calcul_dist(d, &t, dir_x, dir_y);
		render_wall_slice(d, i, &t, ray_angle);
		if (i > 100)
		{
			if (d->file_ != NULL)
			{
				fclose(d->file_);
				d->file_ = NULL;
			}
		}
		i++;
	}
}
