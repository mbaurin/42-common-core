#include "../includes/cub3d.h"

int	cmp_extension(char *file_name, char *want)
{
	file_name = ft_strrchr(file_name, '.');
	return (!(ft_strncmp(file_name, want, ft_strlen(file_name))));
}

void	launch_game(t_map *map)
{
	display_window(map);
	mlx_hook(map->win_ptr, 2, 0, handle_key_press, map);
	mlx_hook(map->win_ptr, 3, 0, handle_key_release, map);
	mlx_hook(map->win_ptr, 17, 0, handle_close, map);
	loop_render(map);
	mlx_loop_hook(map->mlx_ptr, loop_render, map);
	mlx_loop(map->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	*map;

	if (argc > 1 && file_exists(argv[1]) && cmp_extension(argv[1], ".cub"))
	{
		fd = open(argv[1], O_RDONLY);
		map = init_game(fd);
		if (argc > 2)
		{
			if (ft_strncmp(argv[2], "--save", 7) == 0)
			{
				map->res[0] = map->res[0] / map->upscale;
				loop_render_screenshot(map);
				create_bmp(map);
				ft_total_clean(map);
			}
			else
				send_error("The argument is bad, try it with '--save'.", map);
		}
		else
			launch_game(map);
	}
	else
		send_error("You must specify a correct map.", NULL);
	return (1);
}
