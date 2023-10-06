#include "../includes/cub3d.h"

int	handle_close(void *param, int win)
{
	t_map	*map;

	map = param;
	if (win == 1)
	{
		mlx_destroy_image(map->mlx_ptr, map->img_data.img);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	}
	ft_total_clean(map);
	exit(0);
	return (1);
}

int	check_char_map(t_cube c)
{
	if (c.type == '2' || c.type == '1' || c.type == '0' || c.type == 'N'
		|| c.type == 'S' || c.type == 'W' || c.type == 'E' || c.type == ' ')
		return (1);
	return (0);
}
