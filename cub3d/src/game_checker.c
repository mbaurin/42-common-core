#include "../includes/cub3d.h"

void	check_map(t_map *map)
{
	int		is_correct;
	int		i;

	i = 0;
	while (i < (map->x_max * map->y_max))
	{
		is_correct = check_char_map(map->cube[i]);
		if (is_correct != 1)
			send_error("Invalid character in the map", map);
		i++;
	}
}

int	file_exists(char *filename)
{
	int	fd;
	int	i;

	remove_before_space(filename, 1);
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0 || 1 < 1 || read(fd, &i, 0) < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

t_data	gen_file(char *path, t_map *m)
{
	t_data	data;
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (!file_exists(path))
		send_error("Invalid file", m);
	if (cmp_extension(path, ".png"))
		data.img = mlx_png_file_to_image(m->mlx_ptr, path, &w, &h);
	else if (cmp_extension(path, ".xpm"))
		data.img = mlx_xpm_file_to_image(m->mlx_ptr, path, &w, &h);
	else
		send_error("The texture must be a '.png' or '.xpm' file.", m);
	if (data.img == NULL)
		send_error("The imported file is corrupted.", m);
	data.h = h;
	data.w = w;
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	return (data);
}

void	check_settings(t_map *m)
{
	int		w;
	int		h;

	mlx_get_screen_size(m->mlx_ptr, &w, &h);
	if (m->res[0] > w)
		m->res[0] = w;
	if (m->res[1] > h)
		m->res[1] = h;
	if (m->res[0] <= 500)
		m->res[0] = 500;
	if (m->res[1] <= 500)
		m->res[1] = 500;
	m->t_data_no = gen_file(m->no_t_path, m);
	m->t_data_so = gen_file(m->so_t_path, m);
	m->t_data_ea = gen_file(m->ea_t_path, m);
	m->t_data_we = gen_file(m->we_t_path, m);
	m->t_data_sprite = gen_file(m->sprite_t_path, m);
}
