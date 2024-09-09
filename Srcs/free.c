
#include "../Includes/cub3d.h"

void	free_utils(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	
}

void	free_cube(t_data *d)
{
	free_utils(d->mlx);
	free_utils(d->win);
	free_utils(d->img.img);
	free_utils(d->img.addr);
	free_utils(d->north_texture.text_ptr);
	free_utils(d->south_texture.text_ptr);
	free_utils(d->east_texture.text_ptr);
	free_utils(d->west_texture.text_ptr);
	free_tab(d->map);
	free_tab(d->file);
	free_utils(d->text_n_path);
	free_utils(d->text_s_path);
	free_utils(d->text_e_path);
	free_utils(d->text_w_path);
	free_utils(d->ceiling_path);
	free_utils(d->floor_path);
	free_utils(d->minim.minimap);
}
