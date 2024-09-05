
#include "../Includes/cub3d.h"

int mouse_hook(int button, int x, int y)
{
	if (button == 1)
		printf("Clic gauche à (%d, %d)\n", x, y);
	if (button == 2)
		printf("Clic droit à (%d, %d)\n", x, y);
	return (0);
}

void	update_mlx(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	mlx_mouse_hook(d->win, mouse_hook, NULL);
}
