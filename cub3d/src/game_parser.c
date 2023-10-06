#include "../includes/cub3d.h"

t_settings	g_settings[] = {
	{"R", VALUE, ' ', 2},
	{"NO", PATH, 0, 0},
	{"SO", PATH, 0, 0},
	{"WE", PATH, 0, 0},
	{"EA", PATH, 0, 0},
	{"S", PATH, 0, 0},
	{"F", VALUE, ',', 3},
	{"C", VALUE, ',', 3},
	{0, 3, 0, 0}
};

int	get_settings_by_prefix(char *text)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (g_settings[i].id != NULL)
	{
		while (g_settings[i].id[a] == text[a])
			a++;
		if (a == (int)ft_strlen(g_settings[i].id))
			return (i);
		i++;
		a = 0;
	}
	return (-1);
}

void	init_settings_utils(t_map *map, char *text, int ret, void *val)
{
	int	ret_s;

	text = remove_before_space(text, 0);
	ret_s = get_settings_by_prefix(text);
	if ((ret_s == -1) || ret == 0)
		send_error("Wrong prefix or not enough parameters.", map);
	text = text + ft_strlen(g_settings[ret_s].id);
	text = remove_before_space(text, 0);
	if (g_settings[ret_s].type == VALUE)
		val = split_to_int(map, text, g_settings[ret_s].value_to_separate,
				g_settings[ret_s].separator);
	else if (g_settings[ret_s].type == PATH)
		val = text;
	value_to_change(map, ret_s, val);
}

char	*init_cube_map_check_state(t_map *map, int fd, char *text)
{
	int		flag;
	char	*final_text;

	flag = 1;
	final_text = NULL;
	map->state = STATE_JUMP_TO_START;
	while (flag)
	{
		if (map->state == STATE_JUMP_TO_START)
			final_text = check_one(map, fd, text);
		if (map->state == STATE_READ_MAP)
		{
			get_next_line(fd, &text);
			ft_add_to_garbage(text, map);
			if (ft_strlen(text) > 0)
			{
				final_text = symb_string(map, final_text, text);
				map->y_max++;
			}
			else
				flag = 0;
		}
	}
	return (final_text);
}

int	init_cube_map(t_map *map, int fd)
{
	char	*final_text;
	char	*text;

	text = NULL;
	final_text = NULL;
	map->x_max = 0;
	map->y_max = 1;
	final_text = init_cube_map_check_state(map, fd, text);
	init_cube_map_utils(map, fd, text, final_text);
	return (0);
}

t_map	*init_game(int fd)
{
	t_map	*m;

	m = init_default_all_struct();
	m->mlx_ptr = mlx_init();
	init_settings(m, fd);
	init_cube_map(m, fd);
	check_map(m);
	m->cube_size_x = 1;
	m->cube_size_y = 1;
	check_settings(m);
	init_player(m);
	check_hole_in_map(m);
	m->rays->wall_size = ft_safe_malloc(sizeof(int) * (m->res[0]), m);
	m->rays->wall_distance = ft_safe_malloc(sizeof(double) * (m->res[0]), m);
	return (m);
}
