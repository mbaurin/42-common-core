#include "../includes/cub3d.h"

void	look_up(t_map *map)
{
	map->rays->ry = (((int)map->player->y / map->cube_size_x)
			* map->cube_size_x) - 0.0001;
	map->rays->rx = (map->player->y - map->rays->ry)
		* map->rays->tang + map->player->x;
	map->rays->yo = -map->cube_size_x;
	map->rays->xo = -map->rays->yo * map->rays->tang;
}

void	look_down(t_map *map)
{
	map->rays->ry = (((int)map->player->y / map->cube_size_x)
			* map->cube_size_x) + map->cube_size_x;
	map->rays->rx = (map->player->y - map->rays->ry)
		* map->rays->tang + map->player->x;
	map->rays->yo = map->cube_size_x;
	map->rays->xo = -map->rays->yo * map->rays->tang;
}

int	horizontal_rays(t_map *map, int dof)
{
	if (sin(deg_to_rad(map->rays->ra)) > 0.001)
		look_up(map);
	else if (sin(deg_to_rad(map->rays->ra)) < -0.001)
		look_down(map);
	else
	{
		map->rays->rx = map->player->x;
		map->rays->ry = map->player->y;
		dof = 1000;
	}
	return (dof);
}

int	horizontal_hit(t_map *map, int dof)
{
	while (dof < 1000)
	{
		map->rays->mx = (map->rays->rx) / map->cube_size_x;
		map->rays->my = (map->rays->ry) / map->cube_size_x;
		map->rays->mp = map->rays->my * map->x_max + map->rays->mx;
		if (map->rays->mp > 0 && map->rays->mp < map->x_max * map->y_max
			&& get_cube_from_index(map, map->rays->mp).type == '1')
		{
			dof = 1000;
			map->rays->dish = cos(deg_to_rad(map->rays->ra))
				* (map->rays->rx - map->player->x)
				- sin(deg_to_rad(map->rays->ra))
				* (map->rays->ry - map->player->y);
		}
		else
		{
			map->rays->rx += map->rays->xo;
			map->rays->ry += map->rays->yo;
			dof += 1;
		}
	}
	return (dof);
}

void	check_first_hit(t_map *map)
{
	map->rays->sha = 1;
	if (map->rays->disv < map->rays->dish)
	{
		map->rays->sha = 0.5;
		map->rays->rx = map->rays->vx;
		map->rays->ry = map->rays->vy;
		map->rays->dish = map->rays->disv;
	}
	return ;
}
