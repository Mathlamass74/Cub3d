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
	int	wall_height;
	int	start_y;
	int	end_y;
	int	i;
	t_text	*texture;

	wall_height = (WIN_HEIGHT / ray_dist);
	start_y = -wall_height / 2 + WIN_HEIGHT / 2;
	end_y = wall_height / 2 + WIN_HEIGHT / 2;
	if (start_y < 0)
		start_y = 0;
	if (end_y >= WIN_HEIGHT)
		end_y = WIN_HEIGHT - 1;
	i = start_y;
	PI2("end", end_y);
	PI2("i", i);
	while (i < end_y)
	{
		texture = face_texture(d);
		t.target_x = ray_ind;
		t.target_y = (i - start_y) * texture->height / wall_height;
		put_pixel_to_image(&d->img, ray_ind, i,
			get_pixel_from_texture(texture, t.target_x, t.target_y));
		i++;
	}
}

void	go_dda(t_data *d)
{
	int hit;

	hit = 0;
	while (hit == 0 && d->dda.mapx < d->map_lgcol && d->dda.mapy < d->map_rows) // Layer 2, maybe swap to hit == 0;
	{
		if (d->dda.sidedist_x < d->dda.sidedist_y)
		{
			d->dda.sidedist_x += d->dda.deltadist_x;
			d->dda.mapx += d->dda.step_x;
			d->dda.side = 0;
		}
		else
		{
			d->dda.sidedist_y += d->dda.deltadist_y;
			d->dda.mapy += d->dda.step_y;
			d->dda.side = 1;
		}
		if (d->map[d->dda.mapy][d->dda.mapx] != '0')
			hit = 1;
	}
	d->x_door = d->dda.mapx; // check if right
	d->y_door = d->dda.mapy;
	if (d->dda.side == 0)
		d->dda.perpwalldist = (d->dda.sidedist_x - d->dda.deltadist_x);
	else
		d->dda.perpwalldist = (d->dda.sidedist_y - d->dda.deltadist_y);
}

void	draw_multiple_rays(t_data *d, double p_pos_x, double p_pos_y)
{
	int			x;
	t_target	target;

	x = 0;
	target.target_x = 0;
	target.target_y = 0;
	while (x < WIN_WIDTH) // Layer 1
	{
		init_dda_params(d, x, p_pos_x, p_pos_y);
		init_steps(d, p_pos_x, p_pos_y);
		go_dda(d);
		wall_facing(d);
		render_wall_slice(d, x, d->dda.perpwalldist, target);
		x++;
	}
}
