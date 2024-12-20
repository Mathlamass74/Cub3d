/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 11:11:07 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			set_wall_face(d, target, side);
	}
	if (side == 0)
		return (d->ray.dist_x - d->ray.dif_abs_x);
	else
		return (d->ray.dist_y - d->ray.dif_abs_y);
}

void	render_wall_slice(t_data *d, int ray_ind, t_target *t, double ray_angle)
{
	double	wall_height;
	double	start_y;
	double	tex_y_start_offset;
	t_text	*texture;
	int		i;

	tex_y_start_offset = 0;
	texture = get_wall_texture(d, t);
	wall_height = \
		WIN_HEIGHT / (d->ray_dist * cos(d->player.player_angle - ray_angle));
	i = init_wall_dimensions(&start_y, wall_height, t);
	init_texture_pos(d, t, ray_angle);
	texture->tex_x = (d->hit_pos - floor(d->hit_pos)) * texture->width;
	if (WIN_HEIGHT / 2 - wall_height / 2 < 0)
		tex_y_start_offset = ((-((WIN_HEIGHT / 2) - (wall_height / 2))) \
			/ wall_height) * texture->height;
	while (i++ < t->end_y)
	{
		texture->tex_y = (((i - start_y) * texture->height) / wall_height) \
			+ tex_y_start_offset;
		put_pixel_to_image(&d->img, ray_ind, i, \
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
		i++;
	}
}
