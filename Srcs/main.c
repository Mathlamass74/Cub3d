/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/31 10:36:15 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	printmap(t_data *d)\
{
	int	i = 0;
	int j;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			printf("%c", d->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!check_format_cub(av[1]))
			exit(exit_game(9, &data));
		init_data(&data, av[1]);
		parse(&data);
		if (data.exit)
			exit(0);
		if (!fill_map(&data))
			exit(0);
		update_player_dir(&data);
		update_mlx(&data);
		mlx_destroy_image(data.mlx, data.img.img_ptr);
	}
	return (0);
}
