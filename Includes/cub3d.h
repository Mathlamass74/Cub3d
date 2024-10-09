
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
# define MOVE_STEP 0.05
# define ROT_SPEED
# define PI 3.1415926535
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.0174533 //1 degré en radian
# define MINIMAP_WIDTH 256
# define MINIMAP_HEIGHT 205
# define DASH_LENGTH 1
# define TILE_SIZE 64
# define PLAYER_SIZE 4
# define NUM_RAYS 60
# define RAY_LENGTH 2
# define FOV 60
# define TRUE 1
# define FALSE 0
# define MINIMAP_SCALE 32
# define MINIMAP_SIZE 160
# define MOUSE_SENSITIVITY 0.005
# define MOUSE_LEFT_BUTTON 1
# define ROT_ANGLE 0.05
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
	double	camerax;
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
}				t_text;

typedef struct s_target
{
	double		target_x;
	double		target_y;
}				t_target;

typedef struct dda
{
	int			mapx;
	int			mapy;
	int			side;
	double		raydir_x;
	double		raydir_y;
	double		step_x;
	double		step_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
}				t_dda;

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
	t_text			door_o_text;
	t_text			door_c_text;
	t_dda			dda;
	t_mini			mm;
	char			*text_n_path;
	char			*text_s_path;
	char			*text_w_path;
	char			*text_e_path;
	char			*ceiling_path;
	char			*floor_path;
	char			*door_o_path;
	char			*door_c_path;
	int				draw_color;
	int				mouse_x;
	int				mouse_y;
	int				mouse_down;
	bool			window_closed;
	int				move;
	int				x_door;
	int				y_door;
	int				door;
	int				open;
	int				move_check;
	int				face;
	t_target		check_case;
}				t_data;

// init
void	init_data(t_data *d, char *path);
void	init_steps(t_data *d, double posx, double posy);
void	init_dda_params(t_data *d, double p_pos_x, double p_pos_y , int x);
void	init_minimap(t_data *d);
void	init_textures(t_data *d);
int		parse_color(const char *path);
void	create_minimap_window(t_data *d);
void	init_image(t_data *d);

// check
int		check_format_cub(char *file);
bool	check_is_wall(t_data *d, int y, int x);

// update
void	update_map(t_data *d, int i, int j);
void	update_player_dir(t_data *d);
void	update_mlx(t_data *d);
void	load_textures(t_data *d);
void	update_minimap(t_data *d, int x, int y, int option);
void	update_player_pos_in_map(t_data *d, int y, int x);
t_text	*face_texture(t_data *d);

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
void	wall_facing(t_data *d);
int		is_possible_move(t_data *d, double move_angle, double step);
int		mouse_click(int button, int x, int y, t_data *d);

// draw
int		draw_map(t_data *d);
void	draw_minimap(t_data *d);
void	draw_multiple_rays(t_data *d, double p_pos_x, double p_pos_y);
// void	draw_ray(t_data *d, int p_pos_x, int p_pos_y, t_target *target);
void	draw_player(t_data *d, double pos_x, double pos_y);
void	draw_rectangle(t_data *d, int color, int size, int o);
void	put_pixel_to_image(t_img *img, int x, int y, int color);
void	render_floor_ceiling(t_data *d);

// move
int		deal_key(int key, t_data *d);
int		y_move(int key, t_data *d);
int		x_move(int key, t_data *d);
int		mouse_move(int x, int y, t_data *d);
bool	is_colision(t_data *d, double pos_x, double pos_y);
void	check_door(t_data *d, int key, int x, int y);
int		arrow_move(int key, t_data *d);

#endif