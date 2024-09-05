
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
