/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:42:07 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:42:08 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *str, t_lunch *lunch)
{
	if (str)
		write(1, str, ft_strlen(str));
	ft_total_clean(lunch);
	exit(0);
	return ;
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	long			moins;
	long			res;

	i = 0;
	moins = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			moins = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * moins);
}

int	full_digit(char **str)
{
	int	i;
	int	j;

	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] < '0' || str[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

long	get_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
