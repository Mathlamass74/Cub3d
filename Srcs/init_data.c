/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:15:57 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/08/10 14:05:50 by mathieu          ###   ########.fr       */
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
}

void	init_img(t_img *i)
{
	i->img = NULL;
	i->addr = NULL;
	i->bits_per_pixel = 0;
	i->line_length = 0;
	i->endian = 0;
}

void	init_texture(t_data *d)
{
	d->north_texture.text_ptr = NULL;
	d->north_texture.height = 0;
	d->north_texture.width = 0;
	d->south_texture.text_ptr = NULL;
	d->south_texture.height = 0;
	d->south_texture.width = 0;
	d->east_texture.text_ptr = NULL;
	d->east_texture.height = 0;
	d->east_texture.width = 0;
	d->west_texture.text_ptr = NULL;
	d->west_texture.height = 0;
	d->west_texture.width = 0;
}

void	init_map(t_data *d)
{
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
	init_player(&d->player);
	init_map(d);
	d->file = file_cpy(path);
	d->size_of_file	= 0;
	d->tex_width = 0;
	d->tex_height = 0;
	d->floor_color = 0;
	d->ceiling_color = 0;
	d->text_n_path = NULL;
	d->text_s_path = NULL;
	d->text_w_path = NULL;
	d->text_e_path = NULL;
	d->ceiling_path = NULL;
	d->floor_path = NULL;
	init_texture(d);
}
