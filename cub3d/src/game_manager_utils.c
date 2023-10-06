#include "../includes/cub3d.h"

t_cube	get_cube_from_index(t_map *map, int i)
{
	return (map->cube[i]);
}

t_cube	get_cube_from_coords(t_map *map, int x, int y)
{
	return (map->cube[(y * map->x_max) + x]);
}

int	letter_to_angle(char c)
{
	if (c == 'N')
		return (90);
	if (c == 'S')
		return (270);
	if (c == 'W')
		return (180);
	if (c == 'E')
		return (0);
	return (0);
}
