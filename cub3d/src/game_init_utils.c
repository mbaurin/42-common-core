#include "../includes/cub3d.h"

void	init_default_settings(t_map *map)
{
	map->res = NULL;
	map->no_t_path = NULL;
	map->so_t_path = NULL;
	map->we_t_path = NULL;
	map->ea_t_path = NULL;
	map->sprite_t_path = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->nbr_sprite = 0;
	map->sprite = NULL;
	map->square_builder = ft_safe_malloc(sizeof(t_build_square), map);
	map->square_builder->ty = 0;
	map->square_builder->tx = 0;
	map->square_builder->texture_w = 0;
	map->square_builder->to_print = 0;
}

void	init_default_ptrs_img(t_map *map)
{
	map->ptrs = NULL;
	map->img_data.addr = NULL;
	map->img_data.img = NULL;
}

void	init_default_sprite(t_map *map)
{
	map->sprite_i = ft_safe_malloc(sizeof(t_sprite_i), map);
	map->sprite_i->hx = 0;
	map->sprite_i->hy = 0;
	map->sprite_i->p = 0;
	map->sprite_i->q = 0;
	map->sprite_i->sprite_y = 0;
	map->sprite_i->sprite_x = 0;
	map->sprite_i->size_h_r = 0;
	map->sprite_i->size_w_r = 0;
	map->sprite_i->dist_p_s = 0;
	map->sprite_i->a = 0;
	map->sprite_i->b = 0;
	map->sprite_i->color = 0;
}
