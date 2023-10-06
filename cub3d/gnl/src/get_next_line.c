/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:44:50 by mbaurin           #+#    #+#             */
/*   Updated: 2020/12/14 16:13:28 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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
	static char		*cache = NULL;
	int				ret;
	int				i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	while (((ret = read(fd, buff, BUFFER_SIZE))) > 0)
	{
		buff[ret] = '\0';
		cache = joinfree(cache, buff);
		if ((i = where_is_nl(cache)) != -1)
			return (get_line(cache, line, i));
	}
	if (cache)
	{
		if ((i = where_is_nl(cache)) != -1)
			return (get_line(cache, line, i));
		*line = ft_strdup(cache);
		free(cache);
		cache = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}
