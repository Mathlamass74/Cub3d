
#include "../Includes/cub3d.h"

void print_map(t_data *d, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < d->map_rows)
	{
		j = 0;
		while (j < d->map_lgcol)
		{
			if (i == y && j == x)
				printf("%c", d->map[i][j]);
			else
				printf("x");
			j++;
		}
		printf("\n");
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
		if (!check_format_cub(av[1]))
			exit(exit_game(9, &data));
		init_data(&data, av[1]);
		parse(&data);
		if (!fill_map(&data))
			exit(0);
		update_player_dir(&data);
		update_mlx(&data);
	}
	return (0);
}
