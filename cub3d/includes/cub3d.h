#ifndef CUB3D_H
# define CUB3D_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../gnl/includes/get_next_line.h"
# include "../minilibx/mlx.h"
# define PI 3.141592653589793
# define PATH 1
# define VALUE 0
# define STATE_JUMP_TO_START 1
# define STATE_READ_MAP 2

typedef struct s_bmp
{
	char		header[54];
	int			fd;
	int			width;
	int			height;
	int			bytes_number;
	int			width_bytes;
	int			image_s;
	int			bytes_s;
	int			file_s;
	int			header_s;
	int			biplanes;
}				t_bmp;

typedef struct s_settings
{
	const char	*id;
	int			type;
	char		separator;
	int			value_to_separate;
}				t_settings;

typedef struct s_preset_rectangle
{
	int			x_loc;
	int			y_loc;
	int			x_size;
	int			y_size;
	int			padding;
	int			color_up;
	int			color;
	char		*texture;
	int			color_down;
}				t_preset_rectangle;

typedef struct s_cube
{
	double		x;
	double		y;
	char		type;
	int			fixgen;
	double		distance;
}				t_cube;

typedef struct s_sprite
{
	double		x;
	double		y;
	char		type;
	int			fixgen;
	double		distance;
}				t_sprite;

typedef struct s_build_square
{
	float	ty;
	float	tx;
	int		texture_w;
	int		*to_print;
}				t_build_square;

typedef struct s_sprite_i
{
	double	hx;
	double	hy;
	double	p;
	double	q;
	double	sprite_y;
	double	sprite_x;
	int		size_h_r;
	int		size_w_r;
	double	dist_p_s;
	int		a;
	int		b;
	int		color;
}				t_sprite_i;

typedef struct s_player
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		speed;
	float		angle;
	int			ctrl_up;
	int			ctrl_down;
	int			ctrl_right;
	int			ctrl_left;
	int			ctrl_view_right;
	int			ctrl_view_left;
	int			xo;
	int			yo;
	int			ipx;
	int			ipy;
	int			ipx_plus_xo;
	int			ipx_minus_xo;
	int			ipy_plus_yo;
	int			ipy_minus_yo;
}				t_player;

typedef struct s_data
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
}				t_data;

typedef struct s_rays
{
	float		rx;
	float		ry;
	float		vx;
	float		vy;
	float		ra;
	float		xo;
	float		yo;
	int			mx;
	int			my;
	int			mp;
	float		tang;
	float		disv;
	float		sha;
	float		dish;
	double		r_dist;
	int			*wall_size;
	double		*wall_distance;
	int			ca;
	double		lineh;
	double		lineoff;
	float		ty_step;
	float		ty_offset;
}				t_rays;

typedef struct s_map
{
	t_cube			*cube;
	t_sprite		*sprite;
	t_player		*player;
	t_rays			*rays;
	t_sprite_i		*sprite_i;
	t_build_square	*square_builder;
	t_list			*ptrs;
	t_data			img_data;
	t_data			t_data_no;
	t_data			t_data_so;
	t_data			t_data_we;
	t_data			t_data_ea;
	t_data			t_data_sprite;
	t_bmp			*bmp;
	int				*res;
	char			*no_t_path;
	char			*so_t_path;
	char			*we_t_path;
	char			*ea_t_path;
	char			*sprite_t_path;
	int				nbr_sprite;
	int				*floor;
	int				*ceiling;
	int				cube_size_x;
	int				cube_size_y;
	int				x_max;
	int				y_max;
	void			*mlx_ptr;
	void			*win_ptr;
	int				spawn_angle;
	int				spawn_x;
	int				spawn_y;
	int				spawn_is_define;
	int				upscale;
	int				state;
	int				ups;
}					t_map;

void				send_error(char *str, t_map *map);
void				create_bmp(t_map *m);
int					loop_render_screenshot(t_map *map);
t_map				*init_game(int fd);
int					loop_render(t_map *map);
int					handle_close(void *param, int win);
int					handle_key_release(int key, void *param);
int					handle_key_press(int key, void *param);
t_cube				get_cube_from_coords(t_map *map, int x, int y);
int					draw_square(t_preset_rectangle preset, t_map *map,
						t_data s_texture);
int					convert_color(int *rgb, t_map *map);
t_preset_rectangle	pre_format_rectangle_preset(void);
float				deg_to_rad(float a);
t_cube				get_cube_from_index(t_map *map, int i);
void				*ft_safe_malloc(unsigned int size, t_map *s);
void				ft_total_clean(t_map *m);
void				draw_all_sprite(t_map *map);
void				sort_by_dist(t_map *map);
double				get_dist(double x1, double x2, double y1, double y2);
int					move_player(void *param);
float				fix_angle(float a);
void				check_first_hit(t_map *map);
int					horizontal_hit(t_map *map, int dof);
int					horizontal_rays(t_map *map, int dof);
int					vertical_hit(t_map *map, int dof);
int					vertical_rays(t_map *map, int dof);
void				draw_walls(t_map *map, t_data s_texture, double r);
void				put_pixel(t_data img_data, int x, int y, int color);
int					get_pixel(t_data img_data, int x, int y);
void				ctrl_right(t_map *map);
void				ctrl_left(t_map *map);
void				ctrl_down(t_map *map);
void				ctrl_up(t_map *map);
void				init_colision_detection(t_map *map);
char				*symb_string(t_map *map, char *t1, char *t2);
void				add_to_map(char *text, t_map *map);
int					count_char(char *text, char c);
void				gen_cube(int x, int y, char type, t_map *map);
void				init_settings_utils(t_map *map, char *text, int ret,
						void *val);
void				check_hole_in_map(t_map *m);
void				init_player(t_map *map);
void				check_settings(t_map *m);
void				check_map(t_map *map);
int					init_settings(t_map *map, int fd);
t_map				*init_default_all_struct(void);
void				init_cube_map_utils(t_map *map, int fd, char *text,
						char *final_text);
char				*check_one(t_map *map, int fd, char *text);
int					value_to_change(t_map *m, int index, void *value);
int					*split_to_int(t_map *map, char *text, int size, char c);
char				*remove_before_space(char *text, int after);
int					letter_to_angle(char c);
void				init_default_sprite(t_map *map);
void				init_default_ptrs_img(t_map *map);
void				init_default_settings(t_map *map);
int					cmp_extension(char *file_name, char *want);
int					check_char_map(t_cube c);
void				display_window(t_map *map);
void				ft_add_to_garbage(void *ptr, t_map *s);
int					file_exists(char *filename);
void				check_max_size_sprites(t_map *map);
void				check_bug_shit(char *text, t_map *map);
int					je_suis_a_la_norme(t_map *map);

#endif
