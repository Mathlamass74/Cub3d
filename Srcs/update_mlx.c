
#include "../Includes/cub3d.h"

int	mouse_press(int button, int x, int y, t_data *d)
{
	if (button == 1)
	{
		d->mouse_down = 1;
		draw_circle(d, x, y, d->draw_color);
	}
	else if (button == 2)
	{
		if (!d->color_win)
		{
			draw_color_picker(d);
			mlx_hook(d->color_win, 4, 1L << 2, color_picker_click, d);
		}
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *d)
{
	(void)x;
	(void)y;
	if (button == 1 || button == 2)
		d->mouse_down = 0;
	return (0);
}

int	mouse_move(int x, int y, t_data *d)
{
	if (d->mouse_down)
		draw_circle(d, x, y, d->draw_color);
	return (0);
}

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
	mlx_hook(d->win, 4, 1L << 2, mouse_press, d);
	mlx_hook(d->win, 5, 1L << 3, mouse_release, d);
	mlx_hook(d->win, 6, 1L << 6, mouse_move, d);
	mlx_hook(d->win, 2, 1L << 0, &deal_key, d);
	mlx_hook(d->win, 17, 0L, close_window, d);
	update_texture(d);
	draw_map(d);
	mlx_loop(d->mlx);
}
