
#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
// # include "../mlx/mlx.h"
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

# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024
# define MOVE_SPEED
# define ROT_SPEED
# define PI 3.1415926535
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.0174533 //1 degré en radian
# define CIRCLE_RADIUS 16
# define COLOR_WINDOW_WIDTH 200
# define COLOR_WINDOW_HEIGHT 200
# define FOV 360
# define TRUE 1
# define FALSE 0

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
	int				mouse_down;
	int				draw_color;

	void			*color_win;
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
void	print_all(t_data *data);

// drawmap test
int		draw_map(t_data *d);
int		close_window(t_data *d);
int		deal_key(int key, t_data *d);
void	draw_ray(t_data *d, float x_center, float y_center);

// draw color
void	draw_circle(t_data *d, int x_center, int y_center, int color);
void	draw_color_picker(t_data *d);
int		color_picker_click(int button, int x, int y, t_data *d);
int		close_color_window(int button, int x, int y, t_data *d);

#endif