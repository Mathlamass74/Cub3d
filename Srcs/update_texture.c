/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:00:15 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/08/10 14:18:14 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// On charge les textures depuis le path pour chaque face
void	update_texture(t_data *d)
{
	d->north_texture.text_ptr = mlx_xpm_file_to_image(d->mlx, d->text_n_path
		, &d->north_texture.width, &d->north_texture.height);
	if (!d->north_texture.text_ptr)
		exit(exit_game(8));
	d->south_texture.text_ptr = mlx_xpm_file_to_image(d->mlx, d->text_s_path
		, &d->south_texture.width, &d->south_texture.height);
	if (!d->south_texture.text_ptr)
		exit(exit_game(8));
	d->east_texture.text_ptr = mlx_xpm_file_to_image(d->mlx, d->text_e_path
		, &d->east_texture.width, &d->east_texture.height);
	if (!d->east_texture.text_ptr)
		exit(exit_game(8));
	d->west_texture.text_ptr = mlx_xpm_file_to_image(d->mlx, d->text_w_path
		, &d->west_texture.width, &d->west_texture.height);
	if (!d->west_texture.text_ptr)
		exit(exit_game(8));
}
