/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:24:21 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/10/31 11:34:20 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "../minilibx-linux/mlx.h"
# include "../mlx/mlx.h"
# include "../Libft/Includes/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

# define PL fprintf(stderr, "file: %s line: %d pid: %i\n", \
	__FILE__, __LINE__, getpid())
# define PF(x) fprintf(stderr, "PF: %f\n", (x));
# define PF2(s, x) fprintf(stderr, "%s: %f\n", (s), (x));
# define PINT(x) fprintf(stderr, "PI: %d\n", (x));
# define PSTR(x) fprintf(stderr, "PS: %s\n", (x));
# define PI2(s, x) fprintf(stderr, "%s: %d\n", (s), (x));
# define PS2(s, x) fprintf(stderr, "%s: %s\n", (s), (x));

# define FOV 60
# define WIN_WIDTH 1216
# define WIN_HEIGHT 1280
# define MOVE_SPEED 0.05
# define PLAYER_SIZE 4
# define TRUE 1
# define FALSE 0
# define MINIMAP_SCALE 32
# define MINIMAP_SIZE 160
# define MOUSE_SENSITIVITY 0.005
# define ROT_ANGLE 0.05
# define MOUSE_LEFT_BUTTON 1
# define A_KEY 0
# define D_KEY 2
# define E_KEY 14
# define S_KEY 1
# define W_KEY 13
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

# define YELLOW		0xFFFF00
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define PINK		0xFFC0CB
# define BROWN		0x8B4513
# define LIGHT_BLUE	0xADD8E6
# define DARK_GREEN	0x006400
# define GREY		0x808080
# define WHITE		0xFFFFFF
# define BLACK		0x000000

typedef struct s_img
{
	void	*img_ptr;
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
	double	player_angle;
}				t_player;

typedef struct s_text
{
	void	*text_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tex_x;
	int		tex_y;
}				t_text;

typedef struct s_target
{
	double		target_x;
	double		target_y;
	char		face;
	int			end_y;
}				t_target;

typedef struct s_ray_params
{
	double		dif_abs_x;
	double		dif_abs_y;
	double		dist_x;
	double		dist_y;
	int			step_x;
	int			step_y;
}				t_ray_params;

typedef struct s_move
{
	bool	x;
	bool	y;
	bool	z;
	bool	lateral_x;
	bool	lateral_y;
	bool	dirx;
	bool	diry;
}	t_move;

typedef struct s_mini
{
	int				map_x;
	int				map_y;
	int				scale;
	double			minimap_x;
	double			minimap_y;
	double			player_x;
	double			player_y;
}				t_mini;

typedef struct s_door
{
	int				x;
	int				y;
}				t_door;

typedef struct s_check
{
	int				no;
	int				so;
	int				ea;
	int				we;
	int				fl;
	int				ce;
}				t_check;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_move			*move;
	char			**map;
	int				map_rows;
	int				map_cols;
	int				map_index;
	int				map_lgcol;
	int				map_char_counter;
	t_player		player;
	char			**file;
	int				map_width;
	int				map_height;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	t_text			north_texture;
	t_text			south_texture;
	t_text			east_texture;
	t_text			west_texture;
	t_text			door_o_text;
	t_text			door_c_text;
	t_text			zizi_texture;
	t_ray_params	ray;
	t_mini			mm;
	char			*text_n_path;
	char			*text_s_path;
	char			*text_w_path;
	char			*text_e_path;
	char			*ceiling_path;
	char			*floor_path;
	char			*door_o_path;
	char			*door_c_path;
	char			*zizi_path;
	bool			window_closed;
	int				open;
	int				hit;
	int				map_x;
	int				map_y;
	int				cross_door;
	double			hit_pos;
	t_door			*sdoor;
	double			ray_dist;
	int				exit;
	t_check			c_tx;
}				t_data;

// init
int		parse_color(const char *path);
void	init_data(t_data *d, char *path);
void	init_ray(t_ray_params *r);
void	init_ray_params(t_data *d, double dir_x, double dir_y);
void	init_minimap(t_data *d);
void	init_textures(t_data *d);
void	init_image(t_data *d);
void	init_texture_path(t_data *d);
void	init_doors(t_data *d);

// check
int		check_format_cub(char *file);
bool	check_is_wall(t_data *d, int y, int x);
double	check_cross_door_is_valid_move(t_data *d, double step, int option);

// update
void	update_map(t_data *d, int i, int j);
void	update_player_dir(t_data *d);
void	update_mlx(t_data *d);
void	load_textures(t_data *d);
void	update_minimap(t_data *d, int x, int y, int option);
void	update_player_pos_in_map(t_data *d, int y, int x);
t_text	*get_wall_texture(t_data *d, t_target *target);

// utils
int		exit_game(int option, t_data *d);
int		fill_map(t_data *d);
int		check_init_done(t_data *d);
int		close_window(t_data *d);
int		open_door(int button, int x, int y, t_data *d);
int		set_face_side(t_data *d);
int		init_wall_dimensions(double *start_y, double wall_height, t_target *t);
char	*ft_strdup_magic(char *s);
char	**file_cpy(char *path);
void	parse(t_data *d);
void	ft_map_len(t_data *d, int i);
void	free_cube(t_data *d);
void	message(char *msg, int n, t_data *d);
void	set_wall_face(t_data *d, t_target *target, double side);
void	init_texture_pos(t_data *d, t_target *t, double ray_angle);
void	verify_rgb(t_data *d);

// draw
int		get_pixel_from_texture(t_text *texture, int x, int y);
void	draw_minimap(t_data *d);
void	draw_multiple_rays(t_data *d, double dir_x, double dir_y);
void	draw_rectangle(t_data *d, int color, int size, int o);
void	put_pixel_to_image(t_img *img, int x, int y, int color);
void	render_floor_ceiling(t_data *d);

// move
int		key_press(int key, t_data *d);
int		key_release(int key, t_data *d);
int		mouse_move(int x, int y, t_data *d);
int		arrow_move(t_data *d);
void	move_front_back(t_data *d);
void	move_left_right(t_data *d);
void	update_pos(t_data *data);

#endif