/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:11:02 by mathieu           #+#    #+#             */
/*   Updated: 2024/08/10 14:06:10 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_player
{
	char	dir;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_player;

typedef struct s_text
{
	void	*text_ptr;
	int		width;
	int		height;
}				t_text;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			img;
	char			**map;
	int				map_rows;
	int				map_cols;
	int				map_index;
	int				map_lgcol;
	int				map_char_counter;
	t_player		player;
	char			**file;
	int				size_of_file;
	int				map_width;
	int				map_height;
	int				tex_width;
	int				tex_height;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	t_text			north_texture;
	t_text			south_texture;
	t_text			east_texture;
	t_text			west_texture;
	char			*text_n_path;
	char			*text_s_path;
	char			*text_w_path;
	char			*text_e_path;
	char			*ceiling_path;
	char			*floor_path;
}				t_data;

void	init_data(t_data *d, char *path);
int		exit_game(int option);
char	*ft_strdup_magic(char *s);
void	update_map(t_data *d, int	i, int j);
void	parse(t_data *d);
char	**file_cpy(char *path);
void	ft_map_len(t_data *d, int i);
int		fill_map(t_data *d);
int		check_init_done(t_data *d);
void	update_player_dir(t_data *d);
void	update_mlx(t_data *d);
void	update_texture(t_data *d);

// drawmap test
int		draw_map(t_data *d);
int		close_window(t_data *d);
int		deal_key(int key, t_data *d);

#endif