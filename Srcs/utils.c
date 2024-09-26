#include "../Includes/cub3d.h"

void	which_key(int key, t_data *d)
{
	if (key == 0 || key == 1 || key == 2 || key == 13)
		d->move++;
}

// int	nxto(t_data *d)
// {
// 	if (((d->player.posx - TILE_SIZE / 2) / TILE_SIZE
// 			== d->mouse_x / TILE_SIZE - 1 || (d->player.posy - TILE_SIZE / 2) /
// 			TILE_SIZE == d->mouse_y / TILE_SIZE - 1 || (d->player.posx
// 				- TILE_SIZE / 2) / TILE_SIZE == d->mouse_x / TILE_SIZE + 1
// 			|| (d->player.posy - TILE_SIZE / 2) / TILE_SIZE
// 			== d->mouse_y / TILE_SIZE + 1)
// 		&& d->map[d->mouse_y / TILE_SIZE][d->mouse_x / TILE_SIZE] == '2')
// 		return (1);
// 	return (0);
// }

// void	check_door(t_data *d, int key, int x, int y)
// {
// 	if (d->mouse_x <= d->map_lgcol * TILE_SIZE
// 		&& d->mouse_y <= d->map_rows * TILE_SIZE)
// 	{
// 		if (d->map[d->mouse_y / TILE_SIZE][d->mouse_x / TILE_SIZE] == '2' && nxto(d)
// 				&& key == 31 && ((is_colision(d, x, y_move(13, d->player.posy)))
// 				|| (is_colision(d, x, y_move(1, d->player.posy)))
// 				|| (is_colision(d, x_move(0, d->player.posx), y))
// 				|| (is_colision(d, x_move(2, d->player.posx), y))))
// 		{
// 			d->door = 1;
// 			printf ("Door is open\n");
// 		}
// 	}
// }

void	message(char *msg, int n, t_data *d)
{
	printf("%s", msg);
	printf("\033[0m""");
	if (n == 1)
		mlx_destroy_window(d->mlx, d->win);
	if (n == 2)
	{
		d->window_closed = true;
		mlx_destroy_window(d->mlx, d->win);
	}
	exit(0);
}

int	close_window(t_data *d)
{
	d->window_closed = true;
	message("The window has been closed.\n", 1, d);
	return (0);
}

void	wall_facing(t_data *d)
{
	if (d->ray_p.step_x > d->ray_p.step_y)
		d->face = 0;
	if (d->ray_p.step_x < d->ray_p.step_y)
		d->face = 1;
	if (d->ray_p.step_x == d->ray_p.step_y && d->ray_p.step_y < 0)
		d->face = 2;
	if (d->ray_p.step_x == d->ray_p.step_y && d->ray_p.step_y > 0)
		d->face = 3;
}
