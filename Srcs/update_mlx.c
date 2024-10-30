/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 11:11:57 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	draw_zizi(t_data *d)
{
	t_target	t;
	int			zizi_width;
	int			zizi_height;
	int			start_x;
	int			start_y;

	zizi_width = d->zizi_texture.width;
	zizi_height = d->zizi_texture.height;
	start_x = (WIN_WIDTH - zizi_width) / 2;
	start_y = (WIN_HEIGHT - zizi_height) / 1;
	t.target_y = 0;
	while (t.target_y < zizi_height)
	{
		t.target_x = 0;
		while (t.target_x < zizi_width)
		{
			if (get_pixel_from_texture
				(&d->zizi_texture, t.target_x, t.target_y) != 0xFFFFFF)
				put_pixel_to_image(&d->img, start_x + t.target_x, start_y
					+ t.target_y, get_pixel_from_texture(&d->zizi_texture,
						t.target_x, t.target_y));
			t.target_x++;
		}
		t.target_y++;
	}
}

int	update(t_data *d)
{
	update_pos(d);
	render_floor_ceiling(d);
	draw_multiple_rays(d, 0, 0);
	draw_minimap(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
	return (0);
}

void	update_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if (!d->mlx)
	{
		printf("Error\nErreur d'initialisation de mlx\n");
		return ;
	}
	d->win = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!d->win)
	{
		printf("Error\nErreur de création de la fenêtre\n");
		return ;
	}
	init_image(d);
	load_textures(d);
	mlx_hook(d->win, 6, 1L << 6, mouse_move, d);
	mlx_hook(d->win, 17, 0L, close_window, d);
	mlx_hook(d->win, 2, 1L << 0, key_press, d);
	mlx_hook(d->win, 3, 1L << 1, key_release, d);
	mlx_loop_hook(d->mlx, update, d);
	if (d->window_closed == true)
		exit_game(99, d);
	mlx_mouse_hook(d->win, mouse_click, d);
	mlx_loop(d->mlx);
}
