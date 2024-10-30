/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 11:12:08 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static int	is_collision(t_data *d, int x, int y, int option)
{
	if (option == 0)
	{
		if (d->map[(int)y][(int)d->player.posx] != '1'
			&& d->map[(int)y][(int)d->player.posx] != 'D')
			return (0);
	}
	else
	{
		if (d->map[(int)d->player.posy][(int)x] != '1'
			&& d->map[(int)d->player.posy][(int)x] != 'D')
			return (0);
	}
	return (1);
}

void	move_front_back(t_data *d)
{
	double	speed;
	double	x;
	double	y;

	speed = MOVE_SPEED;
	if (d->move->x)
	{
		x = d->player.posx + d->player.dirx * speed * 3;
		y = d->player.posy + d->player.diry * speed * 3;
		if (!is_collision(d, x, y, 0))
			d->player.posy += d->player.diry * speed;
		if (!is_collision(d, x, y, 1))
			d->player.posx += d->player.dirx * speed;
	}
	if (d->move->y)
	{
		x = d->player.posx - d->player.dirx * speed * 3;
		y = d->player.posy - d->player.diry * speed * 3;
		if (!is_collision(d, x, y, 0))
			d->player.posy -= d->player.diry * speed;
		if (!is_collision(d, x, y, 1))
			d->player.posx -= d->player.dirx * speed;
	}
}

void	move_left_right(t_data *d)
{
	double	speed;
	double	x;
	double	y;

	speed = MOVE_SPEED / 2;
	if (d->move->lateral_x)
	{
		x = d->player.posx - d->player.diry * speed * -2;
		y = d->player.posy + d->player.dirx * speed * -2;
		if (!is_collision(d, x, y, 0))
			d->player.posy -= d->player.dirx * speed;
		if (!is_collision(d, x, y, 1))
			d->player.posx += d->player.diry * speed;
	}
	if (d->move->lateral_y)
	{
		x = d->player.posx + d->player.diry * speed * -2;
		y = d->player.posy - d->player.dirx * speed * -2;
		if (!is_collision(d, x, y, 0))
			d->player.posy += d->player.dirx * speed;
		if (!is_collision(d, x, y, 1))
			d->player.posx -= d->player.diry * speed;
	}
}

int	mouse_move(int x, int y, t_data *d)
{
	int	delta_x;

	(void)y;
	delta_x = x - (WIN_WIDTH / 2);
	if (abs(delta_x) < 5)
		return (0);
	d->player.player_angle += delta_x * (M_PI / 180) * MOUSE_SENSITIVITY;
	if (d->player.player_angle < 0)
		d->player.player_angle += 2 * M_PI;
	else if (d->player.player_angle > 2 * M_PI)
		d->player.player_angle -= 2 * M_PI;
	d->player.dirx = cos(d->player.player_angle);
	d->player.diry = sin(d->player.player_angle);
	return (0);
}
