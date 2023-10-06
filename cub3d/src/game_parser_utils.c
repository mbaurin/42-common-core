#include "../includes/cub3d.h"

int	count_char(char *text, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (text[i])
	{
		if (text[i] == c)
			res++;
		i++;
	}
	return (res);
}

void	check_error(char *text, t_map *map, char c)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (!(ft_isdigit(text[i]) || text[i] == c || text[i] == ' '))
			send_error("Parameter values are not valid", map);
		i++;
	}
}

char	*remove_before_space(char *text, int after)
{
	int		i;

	i = 0;
	while (!ft_isprint(text[i]))
		i++;
	while (i > 0)
	{
		text++;
		i--;
	}
	if (after)
	{
		while (ft_isprint(text[i]))
			i++;
		text[i] = '\0';
	}
	return (text);
}

int	get_lenght(t_map *map, char *text, char c, int size)
{
	char	**split;
	int		r;
	int		i;

	r = 0;
	i = 0;
	split = ft_split(text, c);
	ft_add_to_garbage(split, map);
	while (split[i])
		ft_add_to_garbage(split[i++], map);
	i = 0;
	if (c != ' ' && count_char(text, c) != size - 1)
	{
		if (count_char(text, c) != size - 1)
			send_error("Not enough value in the parameters", map);
	}
	else
	{
		while (split[i] && ft_strlen(split[i++]) > 0)
			r++;
		if (r != size)
			send_error("The resolution must consist of 2 values", map);
		i = 0;
	}
	return (i);
}

int	*split_to_int(t_map *map, char *text, int size, char c)
{
	char	**split;
	int		*result;
	int		i;

	i = 0;
	check_error(text, map, c);
	split = ft_split(text, c);
	while (split[i])
		ft_add_to_garbage(split[i++], map);
	i = 0;
	while (split[i])
		check_bug_shit(split[i++], map);
	ft_add_to_garbage(split, map);
	i = get_lenght(map, text, c, size);
	result = ft_safe_malloc((sizeof(int) * size), map);
	while (split[i] && i < size)
	{
		result[i] = ft_atoi(split[i]);
		i++;
	}
	return (result);
}
