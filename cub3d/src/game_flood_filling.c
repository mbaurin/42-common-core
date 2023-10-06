#include "../includes/cub3d.h"

void	flood_fill(int x, int y, t_map *map)
{
	char	*error_msg;

	error_msg = "There are holes in the map.";
	if ((x < 0) || (x >= map->x_max))
		send_error(error_msg, map);
	if ((y < 0) || (y >= map->y_max))
		send_error(error_msg, map);
	if (get_cube_from_coords(map, x, y).type == ' ')
		send_error(error_msg, map);
	if (get_cube_from_coords(map, x, y).type == '0')
	{
		map->cube[y * map->x_max + x].type = 'X';
		flood_fill(x + 1, y - 1, map);
		flood_fill(x + 1, y + 1, map);
		flood_fill(x - 1, y - 1, map);
		flood_fill(x - 1, y + 1, map);
		flood_fill(x + 1, y, map);
		flood_fill(x, y + 1, map);
		flood_fill(x - 1, y, map);
		flood_fill(x, y - 1, map);
	}
}

void	replace_fill_char(t_map *m)
{
	int	i;

	i = 0;
	while (i < (m->x_max * m->y_max))
	{
		if (m->cube[i].type == 'X')
			m->cube[i].type = '0';
		i++;
	}
}

void	check_hole_in_map(t_map *m)
{
	flood_fill(m->spawn_x, m->spawn_y, m);
	replace_fill_char(m);
}
