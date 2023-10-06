#include "../includes/cub3d.h"

int	check_colors(int r, int g, int b, t_map *map)
{
	if ((r < 0 || 255 < r) || (g < 0 || 255 < g) || (b < 0 || 255 < b))
		send_error("Bad color format.", map);
	return (1);
}

int	convert_color(int *rgb, t_map *map)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	color = 0;
	if (!r || !g || !b)
		send_error("Wrong data for the color\n", map);
	if (check_colors(r, g, b, map))
	{
		color = r;
		color = (color << 8) + g;
		color = (color << 8) + b;
	}
	else
		send_error("Wrong data for the color\n", map);
	return (color);
}
