/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 11:10:28 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	key_press(int key, t_data *d)
{
	if (key == 53)
		message("The ESC key pressed.\n", 2, d);
	if (key == 13)
		d->move->x = TRUE;
	if (key == 1)
		d->move->y = TRUE;
	if (key == 0)
		d->move->lateral_x = TRUE;
	if (key == 2)
		d->move->lateral_y = TRUE;
	if (key == RIGHT_ARROW)
		d->move->dirx = TRUE;
	if (key == LEFT_ARROW)
		d->move->diry = TRUE;
	return (0);
}

int	key_release(int key, t_data *d)
{
	if (key == 13)
		d->move->x = FALSE;
	if (key == 1)
		d->move->y = FALSE;
	if (key == 0)
		d->move->lateral_x = FALSE;
	if (key == 2)
		d->move->lateral_y = FALSE;
	if (key == RIGHT_ARROW)
		d->move->dirx = FALSE;
	if (key == LEFT_ARROW)
		d->move->diry = FALSE;
	return (0);
}

void	move_camera_left(t_data *d, double angle)
{
	d->player.player_angle += angle;
	if (d->player.player_angle > 2 * M_PI)
		d->player.player_angle -= 2 * M_PI;
	else if (d->player.player_angle < 0)
		d->player.player_angle += 2 * M_PI;
}

void	move_camera_right(t_data *d, double angle)
{
	d->player.player_angle += angle;
	if (d->player.player_angle > 2 * M_PI)
		d->player.player_angle -= 2 * M_PI;
	else if (d->player.player_angle < 0)
		d->player.player_angle += 2 * M_PI;
}

int	arrow_move(t_data *d)
{
	d->player.dirx = cos(d->player.player_angle);
	d->player.diry = sin(d->player.player_angle);
	if (d->move->diry)
		move_camera_left(d, -ROT_ANGLE);
	else if (d->move->dirx)
		move_camera_right(d, ROT_ANGLE);
	return (0);
}
