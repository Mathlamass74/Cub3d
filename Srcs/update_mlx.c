
#include "../Includes/cub3d.h"

int	update(t_data *d)
{
	load_textures(d);
	mlx_clear_window(d->mlx, d->win);
	//draw_map(d);											// switch this to rendering walls:
	draw_multiple_rays(d, d->player.posx, d->player.posy);	// - Use this function to calculate dist
	draw_minimap(d);										// - And draw columns instead of pixels 
	//draw_player(d, d->player.posx, d->player.posy);
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
	mlx_hook(d->win, 6, 1L << 6, mouse_move, d);
	mlx_hook(d->win, 2, 1L << 0, &deal_key, d);
	mlx_hook(d->win, 17, 0L, close_window, d);
	mlx_loop_hook(d->mlx, update, d);
	if (d->window_closed == true)
		exit_game(99, d);
	mlx_loop(d->mlx);
}
