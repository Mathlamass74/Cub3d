
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
    init_image(d);  // Initialiser l'image avant de dessiner dedans
    //draw_map(d);    // Si vous avez une fonction pour dessiner une minimap ou autre
    draw_multiple_rays(d, d->player.posx, d->player.posy);  // Dessiner les rayons et les murs texturés
	draw_minimap(d);
    mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);  // Afficher l'image finale dans la fenêtre
    mlx_destroy_image(d->mlx, d->img.img_ptr);  // Libérer l'image après chaque frame pour éviter les fuites mémoire
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
    load_textures(d);  // Charger les textures avant d'entrer dans la boucle
    mlx_hook(d->win, 6, 1L << 6, mouse_move, d);  // Mouvement de la souris
    mlx_hook(d->win, 2, 1L << 0, &deal_key, d);   // Gestion des touches
    mlx_hook(d->win, 17, 0L, close_window, d);    // Fermeture de la fenêtre
    mlx_loop_hook(d->mlx, update, d);             // Boucle principale
    if (d->window_closed == true)
        exit_game(99, d);
    mlx_loop(d->mlx);  // Lancer la boucle d'événements de la fenêtre
}