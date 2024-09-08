#include "../Includes/cub3d.h"

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
