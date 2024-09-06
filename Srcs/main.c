
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
	}
	return (0);
}

// Wildcards interdites dans makefile