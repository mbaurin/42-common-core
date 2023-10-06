#include "../includes/cub3d.h"

void	init_colision_detection(t_map *map)
{
	if (map->player->dx < 0)
		map->player->xo = -20;
	else
		map->player->xo = 20;
	if (map->player->dy < 0)
		map->player->yo = -20;
	else
		map->player->yo = 20;
	map->player->ipx = map->player->x / map->cube_size_x;
	map->player->ipx_plus_xo = (map->player->x + map->player->xo)
		/ map->cube_size_x;
	map->player->ipx_minus_xo = (map->player->x - map->player->xo)
		/ map->cube_size_x;
	map->player->ipy = map->player->y / map->cube_size_x;
	map->player->ipy_plus_yo = (map->player->y + map->player->yo)
		/ map->cube_size_x;
	map->player->ipy_minus_yo = (map->player->y - map->player->yo)
		/ map->cube_size_x;
}

void	ctrl_up(t_map *map)
{
	map->player->x += map->player->dx * map->player->speed;
	map->player->y += map->player->dy * map->player->speed;
}

void	ctrl_down(t_map *map)
{
	map->player->x -= map->player->dx * map->player->speed;
	map->player->y -= map->player->dy * map->player->speed;
}

void	ctrl_left(t_map *map)
{
	map->player->y -= map->player->dx * map->player->speed;
	map->player->x += map->player->dy * map->player->speed;
}

void	ctrl_right(t_map *map)
{
	map->player->y += map->player->dx * map->player->speed;
	map->player->x -= map->player->dy * map->player->speed;
}
