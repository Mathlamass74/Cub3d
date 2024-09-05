/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:58:11 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/09/05 11:42:56 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	print_map(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->map_rows)
	{
		printf("%s\n", d->map[i]);
		i++;
	}
}

void	print_all(t_data *d)
{
	printf("text_n_path : %s\n", d->text_n_path);
	printf("text_s_path : %s\n", d->text_s_path);
	printf("text_w_path : %s\n", d->text_w_path);
	printf("text_e_path : %s\n", d->text_e_path);
	printf("ceiling_path : %s\n", d->ceiling_path);
	printf("floor_path : %s\n", d->floor_path);
	printf("player direction : %c\n", d->player.dir);
	printf("player posx : %f\n", d->player.posx);
	printf("player posy : %f\n", d->player.posy);
	//print_map(d);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		init_data(&data, av[1]);
		parse(&data);
		update_player_dir(&data);
		if (!fill_map(&data))
			exit(0);
		update_mlx(&data);
		update_texture(&data);
		mlx_hook(data.win, 2, 1L << 0, &deal_key, &data);
		mlx_hook(data.win, 17, 0L, close_window, &data);
		while (1)
		{
			mlx_clear_window(data.mlx, data.win);
			draw_map(&data);
			mlx_do_sync(data.mlx);
		}
	}
	return (0);
}
