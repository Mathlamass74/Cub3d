
#include "../Includes/cub3d.h"

// int	update(t_data *d)
// {
// 	mlx_clear_window(d->mlx, d->win);
// 	draw_map(d);
// 	draw_multiple_rays(d, d->player.posx, d->player.posy);
// 	return (0);
// }

// void	update_mlx(t_data *d)
// {
// 	d->mlx = mlx_init();
// 	if (!d->mlx)
// 	{
// 		printf("Error\nErreur d'initialisation de mlx\n");
// 		return ;
// 	}
// 	d->win = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
// 	if (!d->win)
// 	{
// 		printf("Error\nErreur de création de la fenêtre\n");
// 		return ;
// 	}
// 	load_textures(d);
// 	mlx_hook(d->win, 6, 1L << 6, mouse_move, d);
// 	mlx_hook(d->win, 2, 1L << 0, &deal_key, d);
// 	mlx_hook(d->win, 17, 0L, close_window, d);
// 	mlx_loop_hook(d->mlx, update, d);
// 	if (d->window_closed == true)
// 		exit_game(99, d);
// 	mlx_loop(d->mlx);
// }

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

// 

// TILESIZE To update:

// update_player.c:
// 	- posx
// 	- posy
// That's the player coordinate on the map, set as the pixel of the window for now but
// needs to be updated as the relative position store as double between 0 and N, N being the rightmost column of the map;
// So when we move, ie. update posx, we will move a certain floating amount, rather than a int.

// draw.c:
// 	- wall_height,
//	That's the proportion of the window screen which will be rendered as wall texture
//	Which seems correct but needs to find an alternative to the tilesize calculs
//	- x_door
//	- y_door
//	- target_x

// utils2.c:
//	- new_y
//	- new_x
