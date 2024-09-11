
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

# define WIN_WIDTH 1216
# define WIN_HEIGHT 1280
# define MOVE_SPEED
# define ROT_SPEED
# define PI 3.1415926535
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.0174533 //1 degré en radian
# define MINIMAP_WIDTH 256
# define MINIMAP_HEIGHT 205
# define DASH_LENGTH 5
# define TILE_SIZE 64
# define PLAYER_SIZE 4
# define FOV 30.0
# define TRUE 1
# define FALSE 0

# define YELLOW 0xFFFF00
# define RED 0xFF0000
# define GREEN 0x00FF00

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

typedef struct s_ray_params
{
	int		dif_abs_x;
	int		dif_abs_y;
	int		step_x;
	int		step_y;
	int		draw_err;
	int		dashed;
}				t_ray_params;

typedef struct s_mini
{
	void			*minimap;
	void			*minimap_mlx;
	void			*minimap_win;
	int				map_x;
	int				map_y;
	int				x;
	int				y;
}				t_mini;

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
	t_ray_params	ray_p;
	t_mini			minim;
	char			*text_n_path;
	char			*text_s_path;
	char			*text_w_path;
	char			*text_e_path;
	char			*ceiling_path;
	char			*floor_path;
	int				draw_color;
	int				mouse_x;
	int				mouse_y;
	int				mouse_down;
	bool			window_closed;
	int				move;
	int				door;
	int				open;
	int				move_check;
}				t_data;

// init
void	init_data(t_data *d, char *path);
void	init_ray(t_ray_params *r);
void	init_ray_params(t_data *d, int p_pos_x, int p_pos_y);
void	init_minimap(t_data *d);
void	create_minimap_window(t_data *d);

// update
void	update_map(t_data *d, int	i, int j);
void	update_player_dir(t_data *d);
void	update_mlx(t_data *d);
void	update_texture(t_data *d);

// utils
int		exit_game(int option, t_data *d);
char	*ft_strdup_magic(char *s);
void	parse(t_data *d);
char	**file_cpy(char *path);
void	ft_map_len(t_data *d, int i);
int		fill_map(t_data *d);
int		check_init_done(t_data *d);
void	print_all(t_data *data);
void	free_cube(t_data *d);
void	message(char *msg, int n, t_data *d);
bool	is_decimal(double n);
int		close_window(t_data *d);
int		nxto(t_data	*d);
void	which_key(int key, t_data *d);

// draw
int		draw_map(t_data *d);
void	draw_minimap(t_data *d);
void	draw_minimap(t_data *d);
void	draw_dashed_line(t_data *d, int p_pos_x, int p_pos_y);
void	draw_ray(t_data *d, double x_center, double y_center);
void	draw_player(t_data *d, double pos_x, double pos_y);

// move
int		deal_key(int key, t_data *d);
double	y_move(int key, double pos);
double	x_move(int key, double pos);
int		mouse_move(int x, int y, t_data *d);
bool	is_colision(t_data *d, double pos_x, double pos_y);
void	check_door(t_data *d, int key, int x, int y);

#endif