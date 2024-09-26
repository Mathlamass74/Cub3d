#include "../Includes/cub3d.h"

int	draw_map(t_data *d)
{
	int	x;
	int	y;
	int	s;

	s = 0;
	y = -1;
	while (++y < d->map_rows)
	{
		x = -1;
		while (++x < d->map_lgcol)
		{
			if (d->map[y][x] == '0')
				mlx_put_image_to_window(d->mlx, d->win,
										d->north_texture.text_ptr, x * s, y * s);
			if (d->map[y][x] == '1')
				mlx_put_image_to_window(d->mlx, d->win,
										d->south_texture.text_ptr, x * s, y * s);
			if (d->map[y][x] == '2')
				mlx_put_image_to_window(d->mlx, d->win,
										d->east_texture.text_ptr, x * s, y * s);
		}
	}
	draw_minimap(d);
	return (0);
}

int	get_pixel_from_texture(t_text *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

// void	render_wall_slice(t_data *d, int ray_ind, double ray_dist, t_target t)
// {
// 	int		wall_height;
// 	int		start_y;
// 	int		end_y;
// 	int		i;
// 	t_text	*texture;

// 	wall_height = (int)(TILE_SIZE / ray_dist * (WIN_WIDTH / 2));
// 	start_y = (WIN_HEIGHT / 2) - (wall_height / 2);
// 	end_y = start_y + wall_height;
// 	if (start_y < 0)
// 		start_y = 0;
// 	if (end_y >= WIN_HEIGHT)
// 		end_y = WIN_HEIGHT - 1;
// 	texture = face_texture(d);
// 	i = start_y;
// 	while (i < end_y)
// 	{
// 		t.target_x = (ray_ind % TILE_SIZE);
// 		t.target_y = (i - start_y) * texture->height / wall_height;
// 		mlx_pixel_put(d->mlx, d->win, ray_ind, i,
// 			get_pixel_from_texture(texture, t.target_x, t.target_y));
// 		i++;
// 	}
// }

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
    char	*dst;

    if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
    {
        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
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
	texture = face_texture(d); // On sélectionne la bonne texture
	i = start_y;
	while (i < end_y)
	{
		t.target_x = (ray_ind % TILE_SIZE); // Calcul de la position dans la texture
		t.target_y = (i - start_y) * texture->height / wall_height; // Position verticale dans la texture
		int color = get_pixel_from_texture(texture, t.target_x, t.target_y);
		put_pixel_to_image(&d->img, ray_ind, i, color); // On dessine dans l'image en mémoire
		i++;
	}
}

// double	draw_ray(t_data *d, int p_pos_x, int p_pos_y, t_target *target)
// {
// 	int		err2;
// 	double	distance;

// 	init_ray_params(d, p_pos_x, p_pos_y, target);
// 	distance = 0;
// 	while (d->map[p_pos_y / TILE_SIZE][p_pos_x / TILE_SIZE] == '0')
// 	{
// 		distance += sqrt(pow(d->ray_p.step_x, 2) + pow(d->ray_p.step_y, 2));
// 		// mlx_pixel_put(d->mlx, d->win, p_pos_x, p_pos_y, YELLOW);
// 		err2 = 2 * d->ray_p.draw_err;
// 		if (err2 > -d->ray_p.dif_abs_y)
// 		{
// 			d->ray_p.draw_err -= d->ray_p.dif_abs_y;
// 			p_pos_x += d->ray_p.step_x;
// 		}
// 		if (err2 < d->ray_p.dif_abs_x)
// 		{
// 			d->ray_p.draw_err += d->ray_p.dif_abs_x;
// 			p_pos_y += d->ray_p.step_y;
// 		}
// 	}
// 	return (distance);
// }

// void	draw_multiple_rays(t_data *d, int p_pos_x, int p_pos_y)
// {
// 	double		angle_step;
// 	double		ray_angle;
// 	t_target	target;
// 	int			i;
// 	double		distance;

// 	angle_step = FOV / (double)(WIN_WIDTH - 1);
// 	i = 0;
// 	while (i < WIN_WIDTH)
// 	{
// 		ray_angle = d->player.player_angle - (FOV / 2 * M_PI / 180)
// 			+ i * angle_step * M_PI / 180;
// 		target.target_x = p_pos_x + cos(ray_angle) * RAY_LENGTH;
// 		target.target_y = p_pos_y + sin(ray_angle) * RAY_LENGTH;
// 		distance = draw_ray(d, p_pos_x, p_pos_y, &target);
// 		wall_facing(d);
// 		distance *= cos(ray_angle - atan2(d->player.diry, d->player.dirx));
// 		render_wall_slice(d, i, distance, target);
// 		i++;
// 	}
// }

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
	}
	return (distance);
}

void	init_image(t_data *d)
{
    d->img.img_ptr = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
    d->img.addr = mlx_get_data_addr(d->img.img_ptr, &d->img.bits_per_pixel,
                                    &d->img.line_length, &d->img.endian);
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
		wall_facing(d); // Détermine quelle face est touchée pour choisir la texture
		distance *= cos(ray_angle - atan2(d->player.diry, d->player.dirx)); // Correction de la distance
		render_wall_slice(d, i, distance, target); // Dessin de la tranche de mur avec texture
		i++;
	}
}
