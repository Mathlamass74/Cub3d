/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 15:24:02 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	init_ray(&d->ray);
	init_player(&d->player);
	init_map(d);
	init_texture_path(d);
	init_doors(d);
	d->move->dirx = FALSE;
	d->move->diry = FALSE;
	d->move->x = FALSE;
	d->move->y = FALSE;
	d->move->lateral_x = FALSE;
	d->move->lateral_y = FALSE;
	d->file = file_cpy(path);
	d->window_closed = false;
	d->open = 0;
	d->cross_door = 0;
	d->map_x = 0;
	d->map_y = 0;
	d->hit_pos = 0;
}
