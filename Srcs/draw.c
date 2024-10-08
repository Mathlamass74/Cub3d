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

void	render_wall_slice(t_data *d, int ray_ind, double ray_dist, t_target t)
{
	int		wall_height;
	int		start_y;
	int		end_y;
	int		i;
	t_text	*texture;

	wall_height = (int)(TILE_SIZE / ray_dist * (WIN_WIDTH / 2));
	start_y = (WIN_HEIGHT / 2) - (wall_height / 2);
	end_y = start_y + wall_height;
	if (start_y < 0)
		start_y = 0;
	if (end_y >= WIN_HEIGHT)
		end_y = WIN_HEIGHT - 1;
	i = start_y;
	while (i < end_y)
	{
		texture = face_texture(d);
		t.target_x = (ray_ind % TILE_SIZE);
		t.target_y = (i - start_y) * texture->height / wall_height;
		put_pixel_to_image(&d->img, ray_ind, i,
			get_pixel_from_texture(texture, t.target_x, t.target_y));
		i++;
	}
}

double	draw_ray(t_data *d, int p_pos_x, int p_pos_y, t_target *target)
{
	int		err2;
	double	distance;

	init_ray_params(d, p_pos_x, p_pos_y, target);
	distance = 0;
	while (d->map[p_pos_y / TILE_SIZE][p_pos_x / TILE_SIZE] == '0')
	{
		distance += sqrt(pow(d->ray_p.step_x, 2) + pow(d->ray_p.step_y, 2));
		err2 = 2 * d->ray_p.draw_err;
		if (err2 > -d->ray_p.dif_abs_y)
		{
			d->ray_p.draw_err -= d->ray_p.dif_abs_y;
			p_pos_x += d->ray_p.step_x;
		}
		if (err2 < d->ray_p.dif_abs_x)
		{
			d->ray_p.draw_err += d->ray_p.dif_abs_x;
			p_pos_y += d->ray_p.step_y;
		}
		d->x_door = p_pos_x / TILE_SIZE;
		d->y_door = p_pos_y / TILE_SIZE;
	}
	return (distance);
}

void	draw_multiple_rays(t_data *d, int p_pos_x, int p_pos_y)
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
		target.target_x = p_pos_x + cos(ray_angle) * RAY_LENGTH;
		target.target_y = p_pos_y + sin(ray_angle) * RAY_LENGTH;
		distance = draw_ray(d, p_pos_x, p_pos_y, &target);
		wall_facing(d);
		distance *= cos(ray_angle - atan2(d->player.diry, d->player.dirx));
		render_wall_slice(d, i, distance, target);
		i++;
	}
}
