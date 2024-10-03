#include "../Includes/cub3d.h"

double	draw_rectangle_utils(t_data *d, int o, char c)
{
	if (o == 0 && c == 'x')
		return (d->mm.player_x);
	else if (o == 0 && c == 'y')
		return (d->mm.player_y);
	else if (o == 1 && c == 'x')
		return (d->mm.map_x);
	else if (o == 1 && c == 'y')
		return (d->mm.map_y);
	else
		return (0);
}

void	draw_player_direction(t_data *d)
{
	double	scale;
	double	dir_x;
	double	dir_y;
	double	angle;

	angle = d->player.player_angle;
	scale = 15;
	dir_x = d->mm.player_x + cos(angle) * scale;
	dir_y = d->mm.player_y + sin(angle) * scale;
	put_pixel_to_image(&d->img, dir_x, dir_y, RED);
}

void	draw_rectangle(t_data *d, int color, int size, int o)
{
	int	i;
	int	j;
	double	x;
	double	y;

	x = draw_rectangle_utils(d, o, 'x');
	y = draw_rectangle_utils(d, o, 'y');
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_to_image(&d->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// void	draw_border(t_data *d, int width, int height, int color)
// {
// 	int	i;

// 	i = 0;
// 	while (i < width)
// 		put_pixel_to_image(&d->img, d->mm.minimap_x
// 			+ i++, d->mm.minimap_y, color);
// 	i = 0;
// 	while (i < width)
// 		put_pixel_to_image(&d->img, d->mm.minimap_x + i++, d->mm.minimap_y + height - 1, color);
// 	i = 0;
// 	while (i < height)
// 		put_pixel_to_image(&d->img, d->mm.minimap_x,
// 			d->mm.minimap_y + i++, color);
// 	i = 0;
// 	while (i < height)
// 		put_pixel_to_image(&d->img, d->mm.minimap_x
// 			+ width - 1, d->mm.minimap_y + i++, color);
// }

void	draw_minimap(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->map_rows)
	{
		x = 0;
		while (x < d->map_lgcol)
		{
			update_minimap(d, x, y, 0);
			if (d->mm.map_x + d->mm.scale > d->mm.minimap_x
				&& d->mm.map_x < d->mm.minimap_x + MINIMAP_SIZE
				&& d->mm.map_y + d->mm.scale > d->mm.minimap_y
				&& d->mm.map_y < d->mm.minimap_y + MINIMAP_SIZE)
				update_minimap(d, x, y, 1234567890);
			x++;
		}
		y++;
	}
	draw_rectangle(d, RED, PLAYER_SIZE, 0);
	draw_player_direction(d);
}
