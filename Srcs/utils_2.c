/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 15:29:43 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	init_ray_params(t_data *d, double dir_x, double dir_y)
{
	d->ray.dif_abs_x = fabs(1 / dir_x);
	d->ray.dif_abs_y = fabs(1 / dir_y);
	if (dir_x < 0)
	{
		d->ray.step_x = -1;
		d->ray.dist_x = (d->player.posx - d->map_x) * d->ray.dif_abs_x;
	}
	else
	{
		d->ray.step_x = 1;
		d->ray.dist_x = (d->map_x + 1.0 - d->player.posx) * d->ray.dif_abs_x;
	}
	if (dir_y < 0)
	{
		d->ray.step_y = -1;
		d->ray.dist_y = (d->player.posy - d->map_y) * d->ray.dif_abs_y;
	}
	else
	{
		d->ray.step_y = 1;
		d->ray.dist_y = (d->map_y + 1.0 - d->player.posy) * d->ray.dif_abs_y;
	}
}

int	is_possible_move(t_data *d, double move_angle, double step)
{
	int	new_y;
	int	new_x;

	new_y = (int)((d->player.posy + (sin(move_angle) * step)));
	new_x = (int)((d->player.posx + (cos(move_angle) * step)));
	return (!check_is_wall(d, new_y, new_x));
}

int	is_door_at_position(double x, double y, t_data *d)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (d->map[map_y][map_x] == 'D' || d->map[map_y][map_x] == 'O')
		return (1);
	return (0);
}

int	open_door(int button, int x, int y, t_data *d)
{
	double	front_x;
	double	front_y;

	(void)x;
	(void)y;
	front_x = d->player.posx + cos(d->player.player_angle);
	front_y = d->player.posy + sin(d->player.player_angle);
	if (is_door_at_position(front_x, front_y, d))
	{
		if (button == MOUSE_LEFT_BUTTON || button == E_KEY)
			d->map[(int)front_y][(int)front_x] = 'O';
	}
	return (0);
}
