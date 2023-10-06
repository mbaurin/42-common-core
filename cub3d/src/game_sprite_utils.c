#include "../includes/cub3d.h"

double	get_dist(double x1, double x2, double y1, double y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

void	sort_by_dist(t_map *map)
{
	int			i;
	t_sprite	tmp_sprite;

	i = 0;
	while (i < map->nbr_sprite - 1)
	{
		if (map->sprite[i].distance < map->sprite[i + 1].distance)
		{
			tmp_sprite = map->sprite[i];
			map->sprite[i] = map->sprite[i + 1];
			map->sprite[i + 1] = tmp_sprite;
			i = -1;
		}
		i++;
	}
}

void	check_max_size_sprites(t_map *map)
{
	if (map->sprite_i->size_h_r > map->res[1])
		map->sprite_i->size_h_r = map->res[1];
	if (map->sprite_i->size_w_r > map->res[0] * map->upscale)
		map->sprite_i->size_w_r = map->res[0] * map->upscale;
}

int	je_suis_a_la_norme(t_map *map)
{
	map->sprite_i->b = -map->sprite_i->size_w_r;
	map->sprite_i->a++;
	return (1);
}
