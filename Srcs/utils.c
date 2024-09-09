#include "../Includes/cub3d.h"

void	check_door(t_data *d, int key, int x, int y)
{
	if (key == 31 && ((is_colision(d, x, y_move(13, d->player.posy)))
			|| (is_colision(d, x, y_move(1, d->player.posy)))
			|| (is_colision(d, x_move(0, d->player.posx), y))
			|| (is_colision(d, x_move(2, d->player.posx), y))))
	{
		d->door = 1;
		printf ("Door is open\n");
	}
}

void	message(char *msg, int n, t_data *d)
{
	printf("%s", msg);
	printf("\033[0m""");
	if (n == 1)
	{
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
