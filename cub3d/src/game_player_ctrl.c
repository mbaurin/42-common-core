#include "../includes/cub3d.h"

int	handle_key_release(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 13)
		map->player->ctrl_up = 0;
	if (key == 0)
		map->player->ctrl_left = 0;
	if (key == 1)
		map->player->ctrl_down = 0;
	if (key == 2)
		map->player->ctrl_right = 0;
	if (key == 123)
		map->player->ctrl_view_left = 0;
	if (key == 124)
		map->player->ctrl_view_right = 0;
	return (1);
}

int	handle_key_press(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 53)
		handle_close(param, 1);
	if (key == 13)
		map->player->ctrl_up = 1;
	if (key == 0)
		map->player->ctrl_left = 1;
	if (key == 1)
		map->player->ctrl_down = 1;
	if (key == 2)
		map->player->ctrl_right = 1;
	if (key == 123)
		map->player->ctrl_view_left = 1;
	if (key == 124)
		map->player->ctrl_view_right = 1;
	return (1);
}

void	move_player_view(t_map *map)
{
	double		speed;

	speed = 2;
	if (map->player->ctrl_view_left)
	{
		map->player->angle += speed;
		map->player->angle = fix_angle(map->player->angle);
		if (map->player->angle < 0)
			map->player->angle += 2 * PI;
		map->player->dx = cos(deg_to_rad(map->player->angle)) * speed;
		map->player->dy = -sin(deg_to_rad(map->player->angle)) * speed;
	}
	if (map->player->ctrl_view_right)
	{
		map->player->angle -= speed;
		map->player->angle = fix_angle(map->player->angle);
		if (map->player->angle < 0)
			map->player->angle += 2 * PI;
		map->player->dx = cos(deg_to_rad(map->player->angle)) * speed;
		map->player->dy = -sin(deg_to_rad(map->player->angle)) * speed;
	}
}

void	move_player_ctrl(t_map *map)
{
	init_colision_detection(map);
	if (map->player->ctrl_up == 1)
		ctrl_up(map);
	if (map->player->ctrl_down == 1)
		ctrl_down(map);
	if (map->player->ctrl_left == 1)
		ctrl_left(map);
	if (map->player->ctrl_right == 1)
		ctrl_right(map);
}

int	move_player(void *param)
{
	t_map	*map;

	map = param;
	move_player_view(map);
	move_player_ctrl(map);
	return (1);
}
