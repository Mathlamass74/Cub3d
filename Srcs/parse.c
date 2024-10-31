/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/31 11:34:07 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	parse_map_utils(t_data *d, int i)
{
	int	j;

	verify_rgb(d);
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

	if (d->c_tx.no > 1 || d->c_tx.so > 1 || d->c_tx.ea > 1
		|| d->c_tx.we > 1 || d->c_tx.fl > 1 || d->c_tx.ce > 1)
		return ;
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
}

int	check_values(t_data *d)
{
	int	i;

	i = 0;
	while (d->file[i] && d->file[i][0] != ' ' && d->file[i][0] != '1')
	{
		if (ft_strncmp(d->file[i], "NO ", 3)
			&& ft_strncmp(d->file[i], "SO ", 3)
			&& ft_strncmp(d->file[i], "EA ", 3)
			&& ft_strncmp(d->file[i], "WE ", 3)
			&& ft_strncmp(d->file[i], "F ", 2)
			&& ft_strncmp(d->file[i], "C ", 2)
			&& ft_strncmp(d->file[i], "\n", 1))
			exit(exit_game(4, d));
		i++;
	}
	return (0);
}

void	parse_2(t_data *d, int i)
{
	if (!ft_strncmp(d->file[i], "NO ", 3))
	{
		d->text_n_path = ft_strdup_magic(d->file[i] + 2);
		d->c_tx.no++;
	}
	else if (!ft_strncmp(d->file[i], "SO ", 3))
	{
		d->text_s_path = ft_strdup_magic(d->file[i] + 2);
		d->c_tx.so++;
	}
	else if (!ft_strncmp(d->file[i], "EA ", 3))
	{
		d->text_e_path = ft_strdup_magic(d->file[i] + 2);
		d->c_tx.ea++;
	}
	else if (!ft_strncmp(d->file[i], "WE ", 3))
	{
		d->text_w_path = ft_strdup_magic(d->file[i] + 2);
		d->c_tx.we++;
	}
	else if (!ft_strncmp(d->file[i], "F ", 2))
	{
		d->floor_path = ft_strdup_magic(d->file[i] + 1);
		d->c_tx.fl++;
	}
}
// On parse le fichier map pour vérifier
// que toutes les infos nécessaires sont bien présentes
void	parse(t_data *d)
{
	int	i;

	i = 0;
	if (check_values(d))
		return ;
	while (d->file[i])
	{
		parse_2(d, i);
		if (!ft_strncmp(d->file[i], "C ", 2))
		{
			d->ceiling_path = ft_strdup_magic(d->file[i] + 1);
			d->c_tx.ce++;
		}
		else if (d->file[i][0] != '\n' && d->text_n_path && d->text_s_path
			&& d->text_e_path && d->text_w_path && d->floor_path
				&& d->ceiling_path && d->c_tx.no == 1 && d->c_tx.so == 1
				&& d->c_tx.ea == 1 && d->c_tx.we == 1 && d->c_tx.fl == 1
				&& d->c_tx.ce == 1)
			return (parse_map(d, i));
		i++;
	}
	
	if (check_init_done(d))
		exit(exit_game(4, d));
}
