#include "../includes/cub3d.h"

int	value_to_change(t_map *m, int index, void *value)
{
	if (index == 0)
		m->res = value;
	if (index == 1)
		m->no_t_path = value;
	if (index == 2)
		m->so_t_path = value;
	if (index == 3)
		m->we_t_path = value;
	if (index == 4)
		m->ea_t_path = value;
	if (index == 5)
		m->sprite_t_path = value;
	if (index == 6)
		m->floor = value;
	if (index == 7)
		m->ceiling = value;
	return (0);
}

int	is_settings_line(char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (ft_isprint(text[i]))
			return (1);
		i++;
	}
	return (0);
}

int	init_settings(t_map *map, int fd)
{
	int		i;
	char	*text;
	void	*val;
	int		ret;

	i = 0;
	val = NULL;
	while (i < 8)
	{
		ret = get_next_line(fd, &text);
		ft_add_to_garbage(text, map);
		if (is_settings_line(text) == 1)
		{
			init_settings_utils(map, text, ret, val);
			i++;
		}
	}
	return (0);
}

void	add_to_map(char *text, t_map *map)
{
	int		a;
	int		x;
	int		y;

	a = 0;
	x = 0;
	y = 0;
	text++;
	while (text[a])
	{
		if (text[a] == '\n')
		{
			while (x < map->x_max)
				gen_cube(x++, y, ' ', map);
			x = 0;
			y++;
		}
		else
			gen_cube(x++, y, text[a], map);
		a++;
	}
	while (x < map->x_max)
		gen_cube(x++, y, '0', map);
}

char	*symb_string(t_map *map, char *t1, char *t2)
{
	char	*result;
	int		i;
	int		a;
	int		total_size;

	i = 0;
	a = 0;
	total_size = 0;
	total_size += ft_strlen(t2);
	if (map->x_max < total_size)
		map->x_max = total_size;
	total_size += 2;
	if (t1 != NULL)
		total_size += ft_strlen(t1);
	result = ft_safe_malloc(sizeof(char) * (total_size), map);
	while (t1 != NULL && t1[i])
		result[a++] = t1[i++];
	result[a] = '\n';
	a++;
	i = 0;
	while (t2[i])
		result[a++] = t2[i++];
	result[a] = '\0';
	return (result);
}
