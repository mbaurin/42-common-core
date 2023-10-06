#include "../includes/cub3d.h"

void	calcul_sprites(t_map *map, double x, double y)
{
	x = x + 0.5;
	y = y + 0.5;
	map->sprite_i->hx = x - map->player->x;
	map->sprite_i->hy = y - map->player->y;
	map->sprite_i->p = atan2(-map->sprite_i->hy,
			map->sprite_i->hx) * (180 / PI);
	if (map->sprite_i->p > 360)
		map->sprite_i->p -= 360;
	if (map->sprite_i->p < 0)
		map->sprite_i->p += 360;
	map->sprite_i->q = map->player->angle + 30 - map->sprite_i->p;
	if (map->sprite_i->p > 270 && map->player->angle < 90)
		map->sprite_i->q = map->player->angle + 30
			- map->sprite_i->p + 360;
	if (map->player->angle > 270 && map->sprite_i->p < 90)
		map->sprite_i->q = map->player->angle + 30
			- map->sprite_i->p - 360;
	map->sprite_i->dist_p_s = get_dist(x, map->player->x,
			y, map->player->y);
	map->sprite_i->size_h_r = map->res[1] / map->sprite_i->dist_p_s;
	map->sprite_i->size_w_r = ((map->res[0] * map->upscale)
			/ map->sprite_i->dist_p_s) / 2;
	check_max_size_sprites(map);
}

int	get_color_texture_sprites(t_map *map, int tx, int ty)
{
	int	color;

	color = get_pixel(map->t_data_sprite, (double)tx
			* ((double)map->t_data_sprite.w
				/ ((double)map->sprite_i->size_w_r
					* (double)2)), (double)ty
			* ((double)map->t_data_sprite.h
				/ ((double)map->sprite_i->size_h_r * (double)2)));
	return (color);
}

void	get_textures_sprites(t_map *map, double x, double y)
{
	int		tx;
	int		ty;
	int		sp_xb;

	ty = 0;
	while (map->sprite_i->a < map->sprite_i->size_h_r)
	{
		tx = 0;
		while (map->sprite_i->b < map->sprite_i->size_w_r)
		{
			sp_xb = (int)map->sprite_i->sprite_x + (int)map->sprite_i->b;
			if (sp_xb < map->res[0] * map->upscale
				&& map->sprite_i->dist_p_s < map->rays->wall_distance[sp_xb])
			{
				x = map->sprite_i->sprite_x + map->sprite_i->b;
				y = map->sprite_i->sprite_y + map->sprite_i->a;
				map->sprite_i->color = get_color_texture_sprites(map, tx, ty);
				if (map->sprite_i->color != 0x000000)
					put_pixel(map->img_data, x, y, map->sprite_i->color);
			}
			tx++;
			map->sprite_i->b++;
		}
		ty += je_suis_a_la_norme(map);
	}
}

void	handle_sprite(t_map *map, double x, double y)
{
	calcul_sprites(map, x, y);
	map->sprite_i->a = -map->sprite_i->size_h_r;
	map->sprite_i->b = -map->sprite_i->size_w_r;
	map->sprite_i->sprite_x = map->sprite_i->q
		* map->res[0] * map->upscale / 60;
	map->sprite_i->sprite_y = map->res[1] / 2;
	get_textures_sprites(map, x, y);
}

void	draw_all_sprite(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nbr_sprite)
	{
		handle_sprite(map, map->sprite[i].x, map->sprite[i].y);
		i++;
	}
	return ;
}
