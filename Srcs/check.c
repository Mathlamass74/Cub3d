/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:51:59 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/08/10 14:15:45 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// On vérifie que la map ne possède pas de trous ni de caractères invalides ni de doublons de perso
int	flood_fill(t_data *d, int x, int y)
{
	if (y >= 0 && y < d->map_rows - 1 && d->map[y][x] == '9'
		&& d->map[y + 1][x] != '9' && d->map[y + 1][x] != '1')
		return (1);
	else if (y <= d->map_rows - 1 && y > 1 && d->map[y][x] == '9'
		&& d->map[y - 1][x] != '9' && d->map[y - 1][x] != '1')
		return (1);
	else if (x >= 0 && x < d->map_lgcol - 1 && d->map[y][x] == '9'
		&& d->map[y][x + 1] != '9' && d->map[y][x + 1] != '1')
		return (1);
	else if (x <= d->map_lgcol - 1 && x > 1 && d->map[y][x] == '9'
		&& d->map[y][x - 1] != '9' && d->map[y][x - 1] != '1')
		return (1);
	if (d->map[y][x] == 'N' || d->map[y][x] == 'S'
		|| d->map[y][x] == 'E' || d->map[y][x] == 'W')
	{
		d->map_char_counter++;
		d->player.dir = d->map[y][x];
	}
	if (d->map[y][x] != 'N' && d->map[y][x] != 'S' && d->map[y][x] != 'E'
		&& d->map[y][x] != 'W' && d->map[y][x] != '1' && d->map[y][x] != '9'
		&& d->map[y][x] != '0')
		return (2);
	return (0);
}

int	fill_map(t_data *d)
{
	int	y;
	int	x;
	int	ret;

	y = 0;
	ret = 0;
	while (y < d->map_rows)
	{
		x = 0;
		while (d->map[y][x])
		{
			ret = flood_fill(d, x, y);
			if (ret == 1)
				return (exit_game(3));
			else if (ret == 2)
				return (exit_game(6));
			x++;
		}
		y++;
	}
	if (d->map_char_counter > 1)
		return (exit_game(5));
	else if (d->map_char_counter < 1)
		return (exit_game(7));
	return (1);
}

int	check_init_done(t_data *d)
{
	if (d->map && d->text_n_path && d->text_s_path && d->text_e_path
		&& d->text_w_path && d->floor_path && d->ceiling_path)
		return (0);
	return (1);
}
