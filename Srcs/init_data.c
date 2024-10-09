
#include "../Includes/cub3d.h"

// Initialisation de toutes les variables
void	init_player(t_player *p)
{
	p->dir = '\0';
	p->posx = 0.0;
	p->posy = 0.0;
	p->dirx = 0.0;
	p->diry = 0.0;
	p->planex = 0.0;
	p->planey = 0.0;
	p->player_angle = 0.0;
}

void	init_img(t_img *i)
{
	i->img_ptr = NULL;
	i->addr = NULL;
	i->bits_per_pixel = 0;
	i->line_length = 0;
	i->endian = 0;
}

void	init_minimap(t_data *d)
{
	d->mm.minimap_x = 0;
	d->mm.minimap_y = 0;
	d->mm.player_x = d->mm.minimap_x
		+ (MINIMAP_SIZE / 2) - (PLAYER_SIZE / 2);
	d->mm.player_y = d->mm.minimap_y
		+ (MINIMAP_SIZE / 2) - (PLAYER_SIZE / 2);
	d->mm.map_x = 0;
	d->mm.map_y = 0;
	d->mm.scale = MINIMAP_SCALE;
}

void	init_map(t_data *d)
{
	init_minimap(d);
	init_textures(d);
	d->map = NULL;
	d->map_cols = 0;
	d->map_rows = 2;
	d->map_index = -1;
	d->map_lgcol = 0;
	d->map_char_counter = 0;
	d->map_width = WIN_WIDTH;
	d->map_height = WIN_HEIGHT;
}

void	init_data(t_data *d, char *path)
{
	d->mlx = NULL;
	d->win = NULL;
	init_img(&d->img);
	init_ray(&d->ray_p);
	init_player(&d->player);
	init_map(d);
	d->file = file_cpy(path);
	d->size_of_file = 0;
	d->floor_color = 0;
	d->ceiling_color = 0;
	d->text_n_path = NULL;
	d->text_s_path = NULL;
	d->text_w_path = NULL;
	d->text_e_path = NULL;
	d->ceiling_path = NULL;
	d->floor_path = NULL;
	d->draw_color = 0xFFFFFF;
	d->window_closed = false;
	d->move = 0;
	d->door = 0;
	d->open = 0;
	d->cross_door = 0;
}
