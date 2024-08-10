/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:49:40 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/07/11 10:47:35 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	update_mlx(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
}
