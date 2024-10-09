#include "../Includes/cub3d.h"

int	get_pixel_from_texture(t_text *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

double	calcul_dist(t_data *d, double p_pos_x, double p_pos_y, t_target *target)
{
	double		err2;
	double		distance;

	init_ray_params(d, p_pos_x, p_pos_y, target);
	distance = 0;
	while (d->map[(int)p_pos_y][(int)p_pos_x] == '0')
	{
		distance += sqrt(pow(d->ray_p.step_x, 2) + pow(d->ray_p.step_y, 2));
		err2 = 2 * d->ray_p.draw_err;
		if (err2 > -d->ray_p.dif_abs_y)
		{
			d->ray_p.draw_err -= d->ray_p.dif_abs_y;
			p_pos_x += d->ray_p.step_x;
			wall_facing(d, target, 0);
		}
		if (err2 < d->ray_p.dif_abs_x)
		{
			d->ray_p.draw_err += d->ray_p.dif_abs_x;
			p_pos_y += d->ray_p.step_y;
			wall_facing(d, target, 1);
		}
		d->x_door = p_pos_x;
		d->y_door = p_pos_y;
	}
	return (distance);
}

void	render_wall_slice(t_data *d, int ray_ind, double ray_dist, t_target t)
{
	double	wall_height;
	double	start_y;
	double	end_y;
	int		i;
	t_text	*texture;

	wall_height = (WIN_HEIGHT / ray_dist);
	start_y = (WIN_HEIGHT / 2) - (wall_height);
	end_y = start_y + wall_height;
	if (start_y < 0)
		start_y = 0;
	if (end_y >= WIN_HEIGHT)
		end_y = WIN_HEIGHT - 1;
	i = start_y;
	texture = face_texture(d, t);
	init_hit_position(d, t);
	while (i < end_y)
	{
		t.target_x = d->hit_position * texture->width;
		t.target_y = (i - start_y) * texture->height / wall_height;
		put_pixel_to_image(&d->img, ray_ind, i,
			get_pixel_from_texture(texture, t.target_x, t.target_y));
		i++;
	}
}

void	draw_multiple_rays(t_data *d, double p_pos_x, double p_pos_y)
{
	double		angle_step;
	double		ray_angle;
	t_target	target;
	int			i;
	double		distance;

	angle_step = FOV / (double)(WIN_WIDTH - 1);
	i = 0;
	while (i < WIN_WIDTH)
	{
		ray_angle = d->player.player_angle - (FOV / 2 * M_PI / 180)
			+ i * angle_step * M_PI / 180;
		target.target_x = p_pos_x + cos(ray_angle);
		target.target_y = p_pos_y + sin(ray_angle);
		distance = calcul_dist(d, p_pos_x, p_pos_y, &target);
		distance *= cos(ray_angle - atan2(d->player.diry, d->player.dirx));
		render_wall_slice(d, i, distance, target);
		i++;
	}
}
