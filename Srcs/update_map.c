
#include "../Includes/cub3d.h"

// On remplace tous les 0 et les espaces de la map par des 9 pour pouvoir filler la map plus facilement ensuite,
// on copie les 1 et N, S, E ou W de data->file dans data->map

void	update_map(t_data *d, int i, int j)
{
	int	k;

	k = 0;
	d->map_index++;
	d->map[d->map_index] = (char *)malloc((sizeof(char)) * (d->map_lgcol + 1));
	if (!d->map[d->map_index])
		d->map[d->map_index] = NULL;
	while (d->file[i][k] && d->file[i][k] != '\n' && j < d->map_lgcol)
	{
		if ((d->map_index == 0 || d->map_index == d->map_rows - 1)
			|| (j == 0 || j == d->map_lgcol - 1))
			d->map[d->map_index][j] = '9';
		else if (d->file[i][k] == ' ')
		{
			d->map[d->map_index][j] = '9';
			k++;
		}
		else
			d->map[d->map_index][j] = d->file[i][k++];
		j++;
	}
	while (j < d->map_lgcol)
		d->map[d->map_index][j++] = '9';
	d->map[d->map_index][j] = '\0';
}

void	update_minimap(t_data *d, int x, int y, int option)
{
	if (option == 0)
	{
		d->mm.map_x = d->mm.minimap_x + (x * d->mm.scale)
			- (d->player.posx * MINIMAP_SCALE) + (MINIMAP_SIZE / 2);
		d->mm.map_y = d->mm.minimap_y + (y * d->mm.scale)
			- (d->player.posy * MINIMAP_SCALE) + (MINIMAP_SIZE / 2);
	}
	else
	{
		if (d->map[y][x] == '1' || d->map[y][x] == '9')
			draw_rectangle(d, BLACK, d->mm.scale, 1);
		else if (d->map[y][x] == '0' || d->map[y][x] == 'N'
			|| d->map[y][x] == 'S' || d->map[y][x] == 'E'
			|| d->map[y][x] == 'W')
			draw_rectangle(d, WHITE, d->mm.scale, 1);
		else if (d->map[y][x] == 'D')
			draw_rectangle(d, GREY, d->mm.scale, 1);
	}
}
