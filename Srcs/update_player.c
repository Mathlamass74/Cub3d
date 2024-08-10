/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:43:02 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/08/10 14:17:05 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// On met à jour les directions du player en fonction de l'orientation
void	update_player_dir(t_data *d)
{
	if (d->player.dir == 'N')
	{
		d->player.diry = -1;
		d->player.planex = 0.66;

	}
	else if (d->player.dir == 'S')
	{
		d->player.diry = 1;
		d->player.planex = -0.66;
	}
	else if (d->player.dir == 'E')
	{
		d->player.dirx = 1;
		d->player.planey = 0.66;
	}
	else if (d->player.dir == 'W')
	{
		d->player.dirx = -1;
		d->player.planey = -0.66;
	}
}
