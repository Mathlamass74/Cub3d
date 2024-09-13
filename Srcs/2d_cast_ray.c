
#include "../Includes/cub3d.h"

bool	is_decimal(double n)
{
	int		i;
	double	f;

	i = n;
	f = n - i;
	if (f > 0)
		return (TRUE);
	else
		return (FALSE);
}

void	draw_ray(t_data *d, double x_center, double y_center)
{
	int		j = 0;
	double	ray_angle;
	double	x, y;
	double	step_length;
	int		max_distance = 500;

	(void)d;
	while (j < 60)
	{
		ray_angle = (j * FOV / 60 - (FOV / 2)) * (PI / 180);
		step_length = 0;
		while (step_length < max_distance)
		{
			x = x_center + cos(ray_angle) * step_length;
			y = y_center + sin(ray_angle) * step_length;
			mlx_pixel_put(d->mlx, d->win, x, y, GREEN);
			step_length += 1;
		}
		j++;
	}
}

// vars missing:
// - 
