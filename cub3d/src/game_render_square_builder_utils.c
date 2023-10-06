#include "../includes/cub3d.h"

void	put_pixel(t_data img_data, int x, int y, int color)
{
	if (x < 0 || x > img_data.w - 1)
		return ;
	if (y < 0 || y > img_data.h - 1)
		return ;
	img_data.addr[((y * (img_data.line_length / 4)) + x)] = color;
	return ;
}

int	get_pixel(t_data img_data, int x, int y)
{
	if (x < 0 || x > img_data.w - 1)
		return (0xFFFFFF);
	if (y < 0 || y > img_data.h - 1)
		return (0xFFFFFF);
	return (img_data.addr[((y * (img_data.line_length / 4)) + x)]);
}
