#include "../includes/cub3d.h"

void	init_cube_map_utils(t_map *map, int fd, char *text, char *final_text)
{
	if (get_next_line(fd, &text) != 0)
		send_error("Too many empty line or bad line", map);
	ft_add_to_garbage(text, map);
	map->cube = ft_safe_malloc(sizeof(t_cube) * (map->x_max * map->y_max), map);
	map->sprite = ft_safe_malloc(sizeof(t_cube)
			* count_char(final_text, '2'), map);
	close(fd);
	add_to_map(final_text, map);
}

char	*check_one(t_map *map, int fd, char *text)
{
	char	*final_text;

	final_text = NULL;
	while (get_next_line(fd, &text) && ft_strlen(text) == 0)
		ft_add_to_garbage(text, map);
	ft_add_to_garbage(text, map);
	final_text = symb_string(map, final_text, text);
	map->state = STATE_READ_MAP;
	return (final_text);
}

void	check_bug_shit(char *text, t_map *map)
{
	int	i;
	int	word;
	int	space;

	space = 0;
	word = 0;
	i = 0;
	while (text[i])
	{
		if (ft_isprint(text[i]))
		{
			word = 1;
			if (space && word)
				send_error("Problem in the format of the values.", map);
		}
		if (word)
			if (!ft_isprint(text[i]))
				space = 1;
		i++;
	}
	return ;
}
