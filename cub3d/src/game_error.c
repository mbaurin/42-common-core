#include "../includes/cub3d.h"

void	send_error(char *str, t_map *map)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	if (map)
		handle_close(map, 0);
}
