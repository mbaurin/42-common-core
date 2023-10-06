#include "../includes/minitalk.h"

static void	exit_server(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	printf("memory error occurred\n");
}

static int	allocate(char **str, size_t c_pos, char c)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (*str == NULL)
	{
		*str = malloc((128 + 1) * sizeof(char *));
		if (*str == NULL)
			return (-1);
		return ((*str)[c_pos] = c);
	}
	if (c_pos >= (c_pos + 1))
	{
		tmp = malloc((128 + 1 + c_pos) * sizeof(char *));
		if (tmp == NULL)
			return (-1);
		while (i < c_pos)
		{
			tmp[i] = (*str)[i];
			i++;
		}
		free(*str);
		tmp[i] = c;
		*str = tmp;
		return (true);
	}
	return ((*str)[c_pos] = c);
}

void	add_c_buffer(char c)
{
	static long	i = 0;
	static char	*str = NULL;
	int			tmp;

	if (c == '\0')
	{
		tmp = allocate(&str, i++, c);
		if (tmp == -1)
			exit_server(&str);
		write(1, str, i);
		free(str);
		str = NULL;
		i = 0;
		send_to_client(SIGUSR2);
		return ;
	}
	tmp = allocate(&str, i++, c);
	if (tmp == -1)
		exit_server(&str);
}
