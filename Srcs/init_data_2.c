#include "../Includes/cub3d.h"

void	init_texture(t_text *texture)
{
	texture->text_ptr = NULL;
	texture->addr = NULL;
	texture->height = 0;
	texture->width = 0;
	texture->line_length = 0;
	texture->bits_per_pixel = 0;
}

void	init_textures(t_data *d)
{
	init_texture(&d->north_texture);
	init_texture(&d->south_texture);
	init_texture(&d->east_texture);
	init_texture(&d->west_texture);
	init_texture(&d->door_c_text);
	init_texture(&d->door_o_text);
	d->door_c_path = ft_strdup("textures/door_close.xpm");
	d->door_o_path = ft_strdup("textures/door_open.xpm");
}
