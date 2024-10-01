
#include "../Includes/cub3d.h"

void	load_texture(t_data *d, t_text *texture, char *file_path)
{
	texture->text_ptr = mlx_xpm_file_to_image(d->mlx, file_path,
			&texture->width, &texture->height);
	if (!texture->text_ptr)
	{
		printf("Erreur : Impossible de charger la texture %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	texture->addr = mlx_get_data_addr(texture->text_ptr,
			&texture->bits_per_pixel, &texture->line_length,
			&texture->endian);
}

void	update_floor_ceiling(t_data *d)
{
	d->floor_color = parse_color(d->floor_path);
	d->ceiling_color = parse_color(d->ceiling_path);
}

void	load_textures(t_data *d)
{
	load_texture(d, &d->north_texture, d->text_n_path);
	load_texture(d, &d->south_texture, d->text_s_path);
	load_texture(d, &d->east_texture, d->text_e_path);
	load_texture(d, &d->west_texture, d->text_w_path);
	load_texture(d, &d->door_c_text, d->door_c_path);
	load_texture(d, &d->door_o_text, d->door_o_path);
	update_floor_ceiling(d);
}

t_text	*face_texture(t_data *d)
{
	if (d->map[d->y_door][d->x_door] == '2')
	{
		if (d->open == 1)
			return (&d->door_o_text);
		else
			return (&d->door_c_text);
		d->y_door = 0;
		d->x_door = 0;
	}
	if (d->face == 0)
		return (&d->north_texture);
	else if (d->face == 1)
		return (&d->south_texture);
	else if (d->face == 2)
		return (&d->east_texture);
	else
		return (&d->west_texture);
}

int	parse_color(const char *path)
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = 0;
	g = 0;
	b = 0;
	i = 0;
	while (path[i] >= '0' && path[i] <= '9')
		r = r * 10 + (path[i++] - '0');
	i++;
	while (path[i] >= '0' && path[i] <= '9')
		g = g * 10 + (path[i++] - '0');
	i++;
	while (path[i] >= '0' && path[i] <= '9')
		b = b * 10 + (path[i++] - '0');
	return ((r << 16) | (g << 8) | b);
}
