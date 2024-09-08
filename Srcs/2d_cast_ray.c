
#include "../Includes/cub3d.h"

bool	is_decimal(float n)
{
	int		i;
	float	f;

	i = n;
	f = n - i;
	if (f > 0)
		return (TRUE);
	else
		return (FALSE);
}

void	draw_ray(t_data *d, float x_center, float y_center)
{
	int		j = 0;
	float	ray_angle;
	float	x, y;
	float	step_length;
	int		max_distance = 500;

	// draw_circle(d->mlx, 500, 500, 0x00ff00);
	while (j < 60)
	{
		ray_angle = (j * FOV / 60 - (FOV / 2)) * (PI / 180);
		step_length = 0;
		while (step_length < max_distance)
		{
			x = x_center + cos(ray_angle) * step_length;
			y = y_center + sin(ray_angle) * step_length;
			if (!is_decimal(x))
				//PF2("x", x);
			if (!is_decimal(y))
				//PF2("y", y);
			mlx_pixel_put(d->mlx, d->win, x, y, GREEN);
			step_length += 1;
		}
		j++;
	}
}

// - Draw a circle as the player with the mlx_pixelput
// 	--> then draw aline from the center of the circle (Eventually in the direction the player's looking)
// $
