#include "../includes/cub3d.h"

void	init_default_player(t_map *map)
{
	map->player = ft_safe_malloc(sizeof(t_player), map);
	map->player->x = 0;
	map->player->y = 0;
	map->player->dx = 0;
	map->player->dy = 0;
	map->player->angle = 0;
	map->player->speed = 0;
	map->player->ctrl_up = 0;
	map->player->ctrl_down = 0;
	map->player->ctrl_right = 0;
	map->player->ctrl_left = 0;
	map->player->ctrl_view_right = 0;
	map->player->ctrl_view_left = 0;
	map->player->xo = 0;
	map->player->yo = 0;
	map->player->ipx = 0;
	map->player->ipy = 0;
	map->player->ipx_minus_xo = 0;
	map->player->ipx_plus_xo = 0;
	map->player->ipy_minus_yo = 0;
	map->player->ipy_plus_yo = 0;
}

void	init_default_rays(t_map *map)
{
	map->rays = ft_safe_malloc(sizeof(t_rays), map);
	map->rays->rx = 0;
	map->rays->ry = 0;
	map->rays->vx = 0;
	map->rays->vy = 0;
	map->rays->ra = 0;
	map->rays->xo = 0;
	map->rays->yo = 0;
	map->rays->mx = 0;
	map->rays->my = 0;
	map->rays->mp = 0;
	map->rays->tang = 0;
	map->rays->dish = 0;
	map->rays->disv = 0;
	map->rays->sha = 1;
	map->rays->ca = 0;
	map->rays->lineh = 0;
	map->rays->lineoff = 0;
	map->rays->ty_step = 0;
	map->rays->ty_offset = 0;
}

t_map	*init_default_all_struct(void)
{
	t_map	*map;

	map = ft_safe_malloc(sizeof(t_map), NULL);
	init_default_ptrs_img(map);
	map->cube = NULL;
	init_default_player(map);
	init_default_rays(map);
	init_default_settings(map);
	init_default_sprite(map);
	map->cube_size_x = 0;
	map->cube_size_y = 0;
	map->y_max = 0;
	map->x_max = 0;
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
	map->spawn_angle = 0;
	map->spawn_x = 0;
	map->spawn_y = 0;
	map->spawn_is_define = 0;
	map->upscale = 4;
	return (map);
}
