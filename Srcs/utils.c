#include "../Includes/cub3d.h"

void	which_key(int key, t_data *d)
{
	if (key == 0 || key == 1 || key == 2 || key == 13)
		d->move++;
}

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

void	render_floor_ceiling(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel_to_image(&d->img, x, y, d->ceiling_color);
			else
				put_pixel_to_image(&d->img, x, y, d->floor_color);
			x++;
		}
		y++;
	}
}
