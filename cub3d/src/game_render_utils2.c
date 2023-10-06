#include "../includes/cub3d.h"

void	look_left(t_map *map)
{
	map->rays->rx = (((int)map->player->x / map->cube_size_x)
			* map->cube_size_x) + map->cube_size_x;
	map->rays->ry = (map->player->x - map->rays->rx)
		* map->rays->tang + map->player->y;
	map->rays->xo = map->cube_size_x;
	map->rays->yo = -map->rays->xo * map->rays->tang;
}

void	look_right(t_map *map)
{
	map->rays->rx = (((int)map->player->x / map->cube_size_x)
			* map->cube_size_x) - 0.0001;
	map->rays->ry = (map->player->x - map->rays->rx)
		* map->rays->tang + map->player->y;
	map->rays->xo = -map->cube_size_x;
	map->rays->yo = -map->rays->xo * map->rays->tang;
}

int	vertical_rays(t_map *map, int dof)
{
	if (cos(deg_to_rad(map->rays->ra)) > 0.001)
		look_left(map);
	else if (cos(deg_to_rad(map->rays->ra)) < -0.001)
		look_right(map);
	else
	{
		map->rays->rx = map->player->x;
		map->rays->ry = map->player->y;
		dof = 1000;
	}
	return (dof);
}

int	vertical_hit(t_map *map, int dof)
{
	while (dof < 1000)
	{
		map->rays->mx = (int)(map->rays->rx) / map->cube_size_x;
		map->rays->my = (int)(map->rays->ry) / map->cube_size_x;
		map->rays->mp = map->rays->my * map->x_max + map->rays->mx;
		if (map->rays->mp > 0 && map->rays->mp < map->x_max * map->y_max
			&& get_cube_from_index(map, map->rays->mp).type == '1')
		{
			dof = 1000;
			map->rays->disv = cos(deg_to_rad(map->rays->ra))
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
