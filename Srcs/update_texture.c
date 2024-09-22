
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

void	load_textures(t_data *d)
{
	load_texture(d, &d->north_texture, d->text_n_path);
	load_texture(d, &d->south_texture, d->text_s_path);
	load_texture(d, &d->east_texture, d->text_e_path);
	load_texture(d, &d->west_texture, d->text_w_path);
}

t_text	*face_texture(t_data *d)
{
	if (d->face == 0)
		return (&d->north_texture);
	else if (d->face == 1)
		return (&d->south_texture);
	else if (d->face == 2)
		return (&d->east_texture);
	else
		return (&d->west_texture);
}
