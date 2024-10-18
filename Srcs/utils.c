#include "../Includes/cub3d.h"

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

void	set_wall_face(t_data *d, t_target *target, double side)
{
	if (side == 0)
	{
		if (d->map[d->map_y][d->map_x] == 'D')
			target->face = 'D';
		else if (d->player.posx < target->target_x)
			target->face = 'S';
		else
			target->face = 'N';
	}
	else
	{
		if (d->map[d->map_y][d->map_x] == 'D')
			target->face = 'P';
		else if (d->player.posy < target->target_y)
			target->face = 'E';
		else
			target->face = 'W';
	}
}

int	set_face_side(t_data *d)
{
	if (d->ray.dist_x < d->ray.dist_y)
	{
		d->ray.dist_x += d->ray.dif_abs_x;
		d->map_x += d->ray.step_x;
		return (0);
	}
	else
	{
		d->ray.dist_y += d->ray.dif_abs_y;
		d->map_y += d->ray.step_y;
		return (1);
	}
}
