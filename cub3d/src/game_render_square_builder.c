#include "../includes/cub3d.h"

t_preset_rectangle	pre_format_rectangle_preset(void)
{
	t_preset_rectangle	preset;

	preset.x_loc = 0;
	preset.y_loc = 0;
	preset.x_size = 0;
	preset.y_size = 0;
	preset.color = 0xFFFFFF;
	preset.padding = 0;
	return (preset);
}

void	check_preset_padding(t_preset_rectangle preset)
{
	if (preset.padding > 0)
	{
		preset.x_size -= preset.padding;
		preset.y_size -= preset.padding;
	}
}

void	apply_shade(t_map *map, t_data s_texture)
{
	map->square_builder->ty = map->rays->ty_offset * map->rays->ty_step;
	map->square_builder->texture_w = s_texture.w;
	if (map->rays->sha == 1)
	{
		map->square_builder->tx = (int)(map->rays->rx
				* map->square_builder->texture_w)
			% map->square_builder->texture_w;
		if (map->rays->ra > 180)
			map->square_builder->tx = map->square_builder->texture_w
				- 1 - map->square_builder->tx;
	}
	else
	{
		map->square_builder->tx = (int)(map->rays->ry
				* map->square_builder->texture_w)
			% map->square_builder->texture_w;
		if (map->rays->ra > 90 && map->rays->ra < 270)
			map->square_builder->tx = map->square_builder->texture_w
				- 1 - map->square_builder->tx;
	}
}

void	fill_square(t_map *map, t_preset_rectangle preset, t_data s_texture)
{
	int		index;
	int		index_q;
	int		color;

	index = 0;
	index_q = 0;
	while (index < map->res[1])
	{
		if (index < preset.y_loc)
			color = preset.color_up;
		else if (index > (preset.y_loc + preset.y_size))
			color = preset.color_down;
		else
		{
			index_q++;
			color = get_pixel(s_texture,
					map->square_builder->tx, map->square_builder->ty);
			map->square_builder->ty += map->rays->ty_step;
		}
		map->square_builder->to_print[index] = color;
		index++;
	}
}

int	draw_square(t_preset_rectangle preset, t_map *map, t_data s_texture)
{
	int		index;

	apply_shade(map, s_texture);
	map->square_builder->to_print = ft_safe_malloc(sizeof(int)
			* map->res[1], map);
	fill_square(map, preset, s_texture);
	map->ups = 0;
	index = 0;
	while (map->ups < map->upscale && (int)preset.x_loc
		+ (int)map->ups < map->res[0] * map->upscale)
	{
		map->rays->wall_distance[(int)preset.x_loc
			+ (int)map->ups] = map->rays->r_dist;
		map->rays->wall_size[(int)preset.x_loc
			+ (int)map->ups] = preset.y_loc + preset.y_size;
		while (index < map->res[1])
		{
			put_pixel(map->img_data, preset.x_loc
				+ map->ups, index, map->square_builder->to_print[index]);
			index++;
		}
		index = 0;
		map->ups++;
	}
	return (1);
}
