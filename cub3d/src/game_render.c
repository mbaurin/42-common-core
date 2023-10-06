#include "../includes/cub3d.h"

void	display_walls(t_map *map, double r)
{
	t_data				s_texture;

	map->rays->r_dist = map->rays->dish;
	map->rays->ca = fix_angle(map->player->angle - map->rays->ra);
	map->rays->dish = map->rays->dish * cos(deg_to_rad(map->rays->ca));
	map->rays->lineh = (map->cube_size_x * map->res[1]) / map->rays->dish;
	s_texture = map->t_data_ea;
	if (map->rays->sha == 1)
	{
		if (map->rays->ra > 180)
			s_texture = map->t_data_so;
		else
			s_texture = map->t_data_no;
	}
	else if (map->rays->ra > 90 && map->rays->ra < 270)
		s_texture = map->t_data_we;
	map->rays->ty_step = (float)s_texture.h / (float)map->rays->lineh;
	map->rays->ty_offset = 0;
	if (map->rays->lineh > map->res[1])
	{
		map->rays->ty_offset = (map->rays->lineh - map->res[1]) / 2.0;
		map->rays->lineh = map->res[1];
	}
	map->rays->lineoff = (map->res[1] - map->rays->lineh) / 2;
	draw_walls(map, s_texture, r);
}

void	process_rays(t_map *map, int dof, double r)
{
	dof = 0;
	map->rays->disv = 100000;
	map->rays->tang = tan(deg_to_rad(map->rays->ra));
	dof = vertical_rays(map, dof);
	dof = vertical_hit(map, dof);
	map->rays->vx = map->rays->rx;
	map->rays->vy = map->rays->ry;
	dof = 0;
	map->rays->dish = 100000;
	map->rays->tang = 1.0 / map->rays->tang;
	dof = horizontal_rays(map, dof);
	dof = horizontal_hit(map, dof);
	check_first_hit(map);
	display_walls(map, r);
	map->rays->ra = fix_angle(map->rays->ra
			- ((double)60 / (double)map->res[0]));
}

int	display_rays(t_map *map)
{
	double					r;
	int						dof;
	int						total_rays;

	total_rays = 60;
	r = 0;
	dof = 0;
	map->rays->ra = fix_angle(map->player->angle + 30);
	while (r <= map->res[0])
		process_rays(map, dof, r++);
	return (1);
}

int	loop_render(t_map *map)
{
	int	i;

	map->img_data.img = mlx_new_image(map->mlx_ptr, map->res[0]
			* map->upscale, map->res[1]);
	map->img_data.addr = (int *)mlx_get_data_addr(map->img_data.img,
			&map->img_data.bits_per_pixel, &map->img_data.line_length,
			&map->img_data.endian);
	map->img_data.w = map->res[0] * map->upscale;
	map->img_data.h = map->res[1];
	move_player(map);
	display_rays(map);
	i = 0;
	while (i < map->nbr_sprite)
	{
		map->sprite[i].distance = get_dist(map->player->x, map->sprite[i].x,
				map->player->y, map->sprite[i].y);
		i++;
	}
	sort_by_dist(map);
	draw_all_sprite(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_data.img, 0, 0);
	return (1);
}

int	loop_render_screenshot(t_map *map)
{
	int	i;

	map->img_data.img = mlx_new_image(map->mlx_ptr, map->res[0]
			* map->upscale, map->res[1]);
	map->img_data.addr = (int *)mlx_get_data_addr(map->img_data.img,
			&map->img_data.bits_per_pixel, &map->img_data.line_length,
			&map->img_data.endian);
	map->img_data.w = map->res[0] * map->upscale;
	map->img_data.h = map->res[1];
	move_player(map);
	display_rays(map);
	i = 0;
	while (i < map->nbr_sprite)
	{
		map->sprite[i].distance = get_dist(map->player->x, map->sprite[i].x,
				map->player->y, map->sprite[i].y);
		i++;
	}
	sort_by_dist(map);
	draw_all_sprite(map);
	return (1);
}
