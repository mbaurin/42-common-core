/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:45:23 by mbaurin           #+#    #+#             */
/*   Updated: 2020/12/14 15:45:25 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

int		where_is_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\n')
		return (-1);
	return (i);
}

int		get_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	i++;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*cache[4096];
	int				ret;
	int				i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	while (((ret = read(fd, buff, BUFFER_SIZE))) > 0)
	{
		buff[ret] = '\0';
		cache[fd] = joinfree(cache[fd], buff);
		if ((i = where_is_nl(cache[fd])) != -1)
			return (get_line(cache[fd], line, i));
	}
	if (cache[fd])
	{
		if ((i = where_is_nl(cache[fd])) != -1)
			return (get_line(cache[fd], line, i));
		*line = ft_strdup(cache[fd]);
		free(cache[fd]);
		cache[fd] = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}
