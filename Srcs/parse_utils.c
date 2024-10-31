/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/31 11:34:13 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static size_t	ft_strlen_magic(char *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			while (s[i] == ' ' || s[i] == '\t')
			{
				k++;
				i++;
			}
			j = k;
		}
		i++;
	}
	return (i - j);
}

char	*ft_strdup_magic(char *s)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	dup = (char *)malloc((sizeof(char)) * (ft_strlen_magic(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			while (s[i] == ' ' || s[i] == '\t')
				i++;
		}
		dup[j] = s[i];
		i++;
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

void	ft_map_len(t_data *d, int i)
{
	int	j;

	j = 0;
	while (d->file[i])
	{
		if (d->file[i][0] != '\n')
			d->map_rows++;
		else if (d->file[i][0] == '\n')
			break ;
		while (d->file[i][j])
			j++;
		if (j >= d->map_lgcol)
			d->map_lgcol = j + 2;
		j = 0;
		i++;
	}
	d->map = (char **)malloc(sizeof(char *) * (d->map_rows + 1));
	if (!d->map)
		exit(exit_game(2, d));
}

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
