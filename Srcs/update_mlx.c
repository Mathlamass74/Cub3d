
#include "../Includes/cub3d.h"

void	update_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if (!d->mlx)
	{
		printf("Erreur d'initialisation de mlx\n");
		return ;
	}
	d->win = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!d->win)
	{
		printf("Erreur de création de la fenêtre\n");
		return ;
	}
	create_minimap_window(d);
	mlx_hook(d->win, 6, 1L << 6, mouse_move, d);
	mlx_hook(d->win, 2, 1L << 0, &deal_key, d);
	mlx_hook(d->win, 17, 0L, close_window, d);
	if (d->window_closed == true)
		exit_game(99, d);
	update_texture(d);
	draw_map(d);
	//draw_ray(d, 500, 500);
	draw_minimap(d);
	mlx_loop(d->mlx);
	mlx_loop(d->minim.minimap_mlx);
}
