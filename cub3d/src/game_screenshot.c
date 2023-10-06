#include "../includes/cub3d.h"

void	fill_bmp_header(t_map *m)
{
	int		i;

	ft_memmove(m->bmp->header, "BM", 2);
	ft_memmove(m->bmp->header + 2, &m->bmp->file_s, 4);
	ft_memmove(m->bmp->header + 10, &m->bmp->header_s, 4);
	ft_memmove(m->bmp->header + 14, &m->bmp->bytes_s, 4);
	ft_memmove(m->bmp->header + 18, &m->bmp->width, 4);
	ft_memmove(m->bmp->header + 22, &m->bmp->height, 4);
	ft_memmove(m->bmp->header + 26, &m->bmp->biplanes, 4);
	ft_memmove(m->bmp->header + 28, &m->bmp->bytes_number, 4);
	ft_memmove(m->bmp->header + 34, &m->bmp->image_s, 4);
	m->bmp->fd = open("./screenshot.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
	i = 0;
	write(m->bmp->fd, m->bmp->header, 54);
	while (i < m->bmp->width)
		write(m->bmp->fd, m->img_data.addr + ((m->bmp->width - i++ - 1)
				* m->img_data.line_length / (m->img_data.bits_per_pixel / 8)),
			m->bmp->width * 4);
	close(m->bmp->fd);
	ft_putstr_fd("The screenshot has just been created.\n", 1);
}

void	create_bmp(t_map *m)
{
	m->bmp = ft_safe_malloc(sizeof(t_bmp), m);
	if (!m->bmp)
		handle_close(m, 1);
	ft_bzero(m->bmp->header, 54);
	m->bmp->width = m->res[0] * m->upscale;
	m->bmp->height = m->res[1];
	m->bmp->bytes_number = 32;
	m->bmp->width_bytes = ((m->bmp->width
				* m->bmp->bytes_number + 31) / 32) * 4;
	m->bmp->image_s = m->bmp->width_bytes * m->bmp->height;
	m->bmp->bytes_s = 40;
	m->bmp->header_s = 54;
	m->bmp->file_s = 54 + m->bmp->image_s;
	m->bmp->biplanes = 1;
	fill_bmp_header(m);
}
