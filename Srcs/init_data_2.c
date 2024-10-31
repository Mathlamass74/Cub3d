/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/31 10:15:16 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	init_ray(t_ray_params *r)
{
	r->dif_abs_x = 0;
	r->dif_abs_y = 0;
	r->step_x = 0;
	r->step_y = 0;
}

void	init_texture(t_text *texture)
{
	texture->text_ptr = NULL;
	texture->addr = NULL;
	texture->height = 0;
	texture->width = 0;
	texture->line_length = 0;
	texture->bits_per_pixel = 0;
	texture->tex_x = 0;
	texture->tex_y = 0;
}

void	init_textures(t_data *d)
{
	init_texture(&d->north_texture);
	init_texture(&d->south_texture);
	init_texture(&d->east_texture);
	init_texture(&d->west_texture);
	init_texture(&d->door_c_text);
	init_texture(&d->door_o_text);
	init_texture(&d->zizi_texture);
	d->door_c_path = ft_strdup("textures/Door-close.xpm");
	d->door_o_path = ft_strdup("textures/door_open.xpm");
	d->zizi_path = ft_strdup("textures/Teub.xpm");
}

void	init_texture_path(t_data *d)
{
	d->floor_color = 0;
	d->ceiling_color = 0;
	d->text_n_path = NULL;
	d->text_s_path = NULL;
	d->text_w_path = NULL;
	d->text_e_path = NULL;
	d->ceiling_path = NULL;
	d->floor_path = NULL;
	d->c_tx.no = 0;
	d->c_tx.so = 0;
	d->c_tx.ea = 0;
	d->c_tx.we = 0;
	d->c_tx.fl = 0;
	d->c_tx.ce = 0;
}

void	init_doors(t_data *d)
{
	d->move = (t_move *)malloc(sizeof(t_move));
	if (!d->move)
	{
		printf(\
		"Error\nImpossible d'allouer la mémoire pour la structure move\n");
		exit(EXIT_FAILURE);
	}
	d->sdoor = (t_door *)malloc(sizeof(t_door));
	if (!d->sdoor)
	{
		printf(\
		"Error\nImpossible d'allouer la mémoire pour la structure sdoor\n");
		exit(EXIT_FAILURE);
	}
	d->sdoor->x = 0;
	d->sdoor->y = 0;
}
