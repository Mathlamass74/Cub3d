
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

void draw_rays_dda(t_data *d, int p_pos_x, int p_pos_y, double player_angle)
{
    double ray_angle;
    double ray_dir_x, ray_dir_y;
    double delta_dist_x, delta_dist_y;
    double side_dist_x, side_dist_y;
	double camera_x;
    int map_x, map_y;
    int i = 0;
    int hit;

    while (i < 60)
    {
        hit = 0;
        // Set the starting position
        map_x = (int)(p_pos_x / TILE_SIZE);
        map_y = (int)(p_pos_y / TILE_SIZE);

		camera_x = 2 * i / 60.0 - 1;  // FOV offset per ray
        ray_angle = player_angle - (i * FOV / 60 - (FOV / 2)) * (PI / 180);

        // Ray direction
        ray_dir_x = d->player.dirx + d->player.planex * camera_x;
        ray_dir_y = d->player.diry + d->player.planey * camera_x;

        // Delta distances for DDA
		if (ray_dir_x == 0)
			ray_dir_x = 0.01;
		if (ray_dir_y == 0)
			ray_dir_y = 0.01;
        delta_dist_x = fabs(1 / ray_dir_x);
        delta_dist_y = fabs(1 / ray_dir_y);

        // Set initial side distances
        if (ray_dir_x < 0)
        {
            d->ray_p.step_x = -1;
            side_dist_x = (p_pos_x / TILE_SIZE - map_x) * delta_dist_x;
        }
        else
        {
            d->ray_p.step_x = 1;
            side_dist_x = (map_x + 1.0 - p_pos_x / TILE_SIZE) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            d->ray_p.step_y = -1;
            side_dist_y = (p_pos_y / TILE_SIZE - map_y) * delta_dist_y;
        }
        else
        {
            d->ray_p.step_y = 1;
            side_dist_y = (map_y + 1.0 - p_pos_y / TILE_SIZE) * delta_dist_y;
        }
        // Perform DDA to find wall
        while (!hit)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += d->ray_p.step_x;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += d->ray_p.step_y;
            }
            // Check for wall hit
            if (d->map[map_y][map_x] != '0')
                hit = 1;
            // Draw the ray
            mlx_pixel_put(d->mlx, d->win, map_x * TILE_SIZE, map_y * TILE_SIZE, GREEN);
        }
        i++;
    }
}
