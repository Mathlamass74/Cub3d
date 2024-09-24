#include "../Includes/cub3d.h"

// void	draw_player(t_data *d, double pos_x, double pos_y)
// {
// 	int	start_x;
// 	int	start_y;
// 	int	x;
// 	int	y;

// 	start_x = (int)pos_x - PLAYER_SIZE / 2;
// 	start_y = (int)pos_y - PLAYER_SIZE / 2;
// 	x = start_x;
// 	while (x < start_x + PLAYER_SIZE)
// 	{
// 		y = start_y;
// 		while (y < start_y + PLAYER_SIZE)
// 		{
// 			mlx_pixel_put(d->mlx, d->win, x, y, RED);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// int	draw_map(t_data *d)
// {
// 	int	x;
// 	int	y;
// 	int	s;

// 	s = 64;
// 	y = -1;
// 	while (++y < d->map_rows)
// 	{
// 		x = -1;
// 		while (++x < d->map_lgcol)
// 		{
// 			if (d->map[y][x] == '0')
// 				mlx_put_image_to_window(d->mlx, d->win,
// 										d->north_texture.text_ptr, x * s, y * s);
// 			if (d->map[y][x] == '1')
// 				mlx_put_image_to_window(d->mlx, d->win,
// 										d->south_texture.text_ptr, x * s, y * s);
// 			if (d->map[y][x] == '2')
// 				mlx_put_image_to_window(d->mlx, d->win,
// 										d->east_texture.text_ptr, x * s, y * s);
// 		}
// 	}
// 	return (0);
// }

// void	render_wall_slice(t_data *d, int ray_index, double ray_distance)
// {
// 	int	wall_height;
// 	int	start_y;
// 	int	end_y;
// 	int	i;
// 	int	color;

// 	wall_height = (int)(TILE_SIZE / ray_distance * (WIN_WIDTH / 2));
// 	start_y = (WIN_HEIGHT / 2) - (wall_height / 2);
// 	end_y = start_y + wall_height;
// 	if (start_y < 0)
// 		start_y = 0;
// 	if (end_y >= WIN_HEIGHT)
// 		end_y = WIN_HEIGHT - 1;
// 	i = start_y;
// 	while (i++ < end_y)
// 	{
// 		color = get_pixel_from_texture();
// 		mlx_pixel_put(d->mlx, d->win, ray_index, i, color);
// 	}
// }

/*
double	get_wall_dist(t_data *d, int p_pos_x, int p_pos_y, t_target *target)
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
		distance = get_wall_dist(d, p_pos_x, p_pos_y, &target);
		wall_facing(d);
		distance *= cos(ray_angle - atan2(d->player.diry, d->player.dirx));
		render_wall_slice(d, i, distance, target);
		i++;
	}
}
*/

int	get_pixel_from_texture(t_text *texture, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = texture->addr + (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
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
	texture = face_texture(d);
	t.target_x = (ray_ind % TILE_SIZE);
	i = start_y;
	while (i < end_y)
	{
		t.target_y = (i - start_y) * texture->height / wall_height;
		mlx_pixel_put(d->mlx, d->win, ray_ind, i,
			get_pixel_from_texture(texture, t.target_x, t.target_y));
		i++;
	}
}

void calculate_step_and_side_dist(t_data *d, t_dda *dda)
{
	if (dda->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = fabs(1 / dda->ray_dir_x);
	if (dda->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = fabs(1 / dda->ray_dir_y);
	if (dda->ray_dir_x < 0)
	{
		d->ray_p.step_x = -1;
		dda->side_dist_x = (d->player.posx - dda->map_pos_x) * (dda->delta_dist_x);
	}
	else
	{
		d->ray_p.step_x = 1;
		dda->side_dist_x = (dda->map_pos_x + 1.0 - d->player.posx) * (dda->delta_dist_x);
	}
	if (dda->ray_dir_y < 0)
	{
		d->ray_p.step_y = -1;
		dda->side_dist_y = (d->player.posy - dda->map_pos_y) * (dda->delta_dist_y);
	}
	else
	{
		d->ray_p.step_y = 1;
		dda->side_dist_y = (dda->map_pos_y + 1.0 - d->player.posy) * (dda->delta_dist_y);
	}
}

double perform_dda(t_data *d, t_dda *dda)
{
	int 	hit = 0;
	int 	side;  // Was the wall hit vertical (0) or horizontal (1)?

	calculate_step_and_side_dist(d, dda);
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			d->player.posx += d->ray_p.step_x;
			side = 0; // Vertical
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_pos_y += d->ray_p.step_y;
			side = 1; // Horizontal
		}
		if (dda->map_pos_x < 0 || dda->map_pos_x >= d->map_cols
			|| dda->map_pos_y < 0 || dda->map_pos_y >= d->map_rows)
		{
			hit = 1;
			break ;
		}
		if (d->map[dda->map_pos_y][dda->map_pos_x] == '1')
			hit = 1;
	}
	if (side == 0)
		return ((dda->map_pos_x - d->player.posx + (1 - d->ray_p.step_x) / 2) / dda->ray_dir_x);
	else
		return ((dda->map_pos_y - d->player.posy + (1 - d->ray_p.step_y) / 2) / dda->ray_dir_y);
}

void calculate_ray_direction(t_dda *dda)
{
	dda->ray_dir_x = cos(dda->ray_angle);
	dda->ray_dir_y = sin(dda->ray_angle);
}

void draw_multiple_rays(t_data *d, int p_pos_x, int p_pos_y)
{
	int			i;
	double		angle_step;
	double		distance;
	t_dda		dda;
	t_target	target;

	i = 0;
	angle_step = FOV / (double)(WIN_WIDTH - 1);
	init_dda(d, &dda);
	while (i < WIN_WIDTH)
	{
		dda.ray_angle = d->player.player_angle - (FOV / 2 * M_PI / 180)
			+ i * angle_step * M_PI / 180;
		target.target_x = p_pos_x + cos(dda.ray_angle) * RAY_LENGTH;
		target.target_y = p_pos_y + sin(dda.ray_angle) * RAY_LENGTH;
		calculate_ray_direction(&dda);
		distance = perform_dda(d, &dda);
		distance *= cos(dda.ray_angle - d->player.player_angle);
		render_wall_slice(d, i, distance, target);
		i++;
	}
}
