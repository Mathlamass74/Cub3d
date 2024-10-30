/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/30 14:00:13 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!check_format_cub(av[1]))
			exit(exit_game(9, &data));
		init_data(&data, av[1]);
		parse(&data);
		if (!fill_map(&data))
			exit(0);
		update_player_dir(&data);
		update_mlx(&data);
		mlx_destroy_image(data.mlx, data.img.img_ptr);
	}
	return (0);
}
