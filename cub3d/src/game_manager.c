#include "../includes/cub3d.h"

char	gen_spawn_point(int x, int y, char type, t_map *map)
{
	if (type == 'N' || type == 'S' || type == 'W' || type == 'E')
	{
		if (map->spawn_is_define == 0)
		{
			map->spawn_is_define++;
			map->spawn_x = x;
			map->spawn_y = y;
			map->spawn_angle = letter_to_angle(type);
		}
		else
			send_error("Too many spawn point", map);
		return ('0');
	}
	return (type);
}

void	gen_cube(int x, int y, char type, t_map *map)
{
	static int	a = 0;
	static int	i = 0;
	t_cube		c;
	t_sprite	s;

	c.type = type;
	c.x = x;
	c.y = y;
	c.distance = 0;
	c.type = gen_spawn_point(x, y, type, map);
	map->cube[i] = c;
	if (c.type == '2')
	{
		s.distance = c.distance;
		s.fixgen = c.fixgen;
		s.type = c.type;
		s.x = c.x;
		s.y = c.y;
		map->sprite[a] = s;
		map->nbr_sprite++;
		a++;
	}
	i++;
}

void	init_player(t_map *map)
{
	if (map->spawn_is_define == 0)
		send_error("No spawn point for player", map);
	map->player->angle = map->spawn_angle;
	map->player->dx = cos(deg_to_rad(map->player->angle)) * 2;
	map->player->dy = -sin(deg_to_rad(map->player->angle)) * 2;
	map->player->x = map->spawn_x * map->cube_size_x + (map->cube_size_x / 2);
	map->player->y = map->spawn_y * map->cube_size_x + (map->cube_size_x / 2);
	map->player->speed = 0.05;
	return ;
}
