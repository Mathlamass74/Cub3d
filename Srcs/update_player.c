/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 22:41:54 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// On met à jour les directions du player en fonction de l'orientation
void	update_player_dir(t_data *d)
{
	if (d->player.dir == 'N')
	{
		d->player.diry = -1;
		d->player.dirx = 0;
		d->player.player_angle = 3 * M_PI / 2;
	}
	else if (d->player.dir == 'S')
	{
		d->player.diry = 1;
		d->player.dirx = 0;
		d->player.player_angle = M_PI / 2;
	}
	else if (d->player.dir == 'E')
	{
		d->player.diry = 0;
		d->player.dirx = 1;
		d->player.player_angle = 0;
	}
	else if (d->player.dir == 'W')
	{
		d->player.diry = 0;
		d->player.dirx = -1;
		d->player.player_angle = M_PI;
	}
}

void	update_player_pos_in_map(t_data *d, int y, int x)
{
	d->map_char_counter++;
	d->player.dir = d->map[y][x];
	d->player.posx = x + 0.5;
	d->player.posy = y + 0.5;
	d->map[y][x] = '0';
}

void	update_pos(t_data *d)
{
	if (d->move->x || d->move->y)
		move_front_back(d);
	if (d->move->lateral_x || d->move->lateral_y)
		move_left_right(d);
	if (d->move->dirx || d->move->diry)
		arrow_move(d);
	if (d->map[(int)d->player.posy][(int)d->player.posx] == 'O')
	{
		d->sdoor->x = (int)d->player.posx;
		d->sdoor->y = (int)d->player.posy;
		d->map[d->sdoor->y][d->sdoor->x] = 'C';
	}
	if (((int)d->player.posx != d->sdoor->x
			|| (int)d->player.posy != d->sdoor->y)
		&& d->map[d->sdoor->y][d->sdoor->x] == 'C')
		d->map[d->sdoor->y][d->sdoor->x] = 'D';
}
