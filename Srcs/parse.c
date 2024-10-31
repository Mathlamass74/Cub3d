/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/31 11:15:53 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	verify_rgb(t_data *d)
{
	char	**floor;
	char	**ceiling;
	int		i;

	i = 0;
	floor = ft_split(d->floor_path, ',');	
	ceiling = ft_split(d->ceiling_path, ',');	
	while (i < 3 && ceiling[i] && floor[i])
	{
		if (ft_atoi(ceiling[i]) < 0 || ft_atoi(ceiling[i]) > 255
			|| ft_atoi(floor[i]) < 0 || ft_atoi(floor[i]) > 255
			|| !ft_isnumber(floor[i])
			|| !ft_isnumber(ceiling[i]))
			(exit_game(4, d), exit(EXIT_FAILURE));
		i++;
	}
}

int	parse_map_utils(t_data *d, int i)
{
	int	j;

	while (d->file[i])
	{
		j = 0;
		while (d->file[i][j])
		{
			if (d->file[i][j] != '0' && d->file[i][j] != '1'
				&& d->file[i][j] != 'N' && d->file[i][j] != 'S'
				&& d->file[i][j] != 'E' && d->file[i][j] != 'W'
				&& d->file[i][j] != 'D' && d->file[i][j] != ' '
				&& d->file[i][j] != '\n')
			{
				d->exit = 1;
				return (exit_game(6, d));
			}
			j++;
		}
		i++;
	}
	return (1);
}

// On copie la map ligne par ligne depuis data->file
void	parse_map(t_data *d, int i)
{
	int	j;

	verify_rgb(d);
	if (!parse_map_utils(d, i))
		return ;
	ft_map_len(d, i);
	update_map(d, i, 0);
	while (d->file[i])
	{
		d->map_cols = 2;
		j = 0;
		if (d->file[i][0] == '\n')
			break ;
		while (d->file[i][j])
		{
			if (d->file[i][j] != '\n')
				d->map_cols++;
			j++;
		}
		update_map(d, i, 0);
		i++;
	}
	update_map(d, i - 1, 0);
	if (check_init_done(d))
		exit(exit_game(4, d));
}

// On parse le fichier map pour vérifier
// que toutes les infos nécessaires sont bien présentes
void	parse(t_data *d)
{
	int	i;

	i = 0;
	while (d->file[i])
	{
		if (!d->text_n_path && !ft_strncmp(d->file[i], "NO ", 3))
			d->text_n_path = ft_strdup_magic(d->file[i] + 2);
		else if (!d->text_s_path && !ft_strncmp(d->file[i], "SO ", 3))
			d->text_s_path = ft_strdup_magic(d->file[i] + 2);
		else if (!d->text_e_path && !ft_strncmp(d->file[i], "EA ", 3))
			d->text_e_path = ft_strdup_magic(d->file[i] + 2);
		else if (!d->text_w_path && !ft_strncmp(d->file[i], "WE ", 3))
			d->text_w_path = ft_strdup_magic(d->file[i] + 2);
		else if (!d->floor_path && !ft_strncmp(d->file[i], "F ", 2))
			d->floor_path = ft_strdup_magic(d->file[i] + 1);
		else if (!d->ceiling_path && !ft_strncmp(d->file[i], "C ", 2))
			d->ceiling_path = ft_strdup_magic(d->file[i] + 1);
		else if (d->file[i][0] != '\n' && d->text_n_path && d->text_s_path
			&& d->text_e_path && d->text_w_path && d->floor_path
				&& d->ceiling_path)
			return (parse_map(d, i));
		i++;
	}
}
