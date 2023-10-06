#include "../includes/cub3d.h"

float	fix_angle(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

float	deg_to_rad(float a)
{
	return (a * M_PI / 180.0);
}

void	display_window(t_map *map)
{
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->res[0],
			map->res[1], "Cube3D");
	map->res[0] = map->res[0] / map->upscale;
}

void	draw_walls(t_map *map, t_data s_texture, double r)
{
	t_preset_rectangle	wall;

	wall = pre_format_rectangle_preset();
	wall.x_loc = r * map->upscale;
	wall.y_loc = map->rays->lineoff;
	wall.y_size = map->rays->lineh;
	wall.color_up = convert_color(map->ceiling, map);
	wall.color_down = convert_color(map->floor, map);
	wall.texture = map->ea_t_path;
	draw_square(wall, map, s_texture);
}
