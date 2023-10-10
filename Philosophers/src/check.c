/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:41:41 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:41:43 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_all_finish(t_lunch *lunch)
{
	int	i;

	i = 0;
	if (lunch->args.number_of_times_each_philo_must_eat == -1)
		return (0);
	while (i < lunch->args.total_philosophers)
	{
		if (lunch->philo[i]->nb_eat > 0)
			return (0);
		i++;
	}
	set_printable(0, lunch);
	return (1);
}

int	is_someone_died(t_lunch *lunch)
{
	int	i;

	i = 0;
	while (i < lunch->args.total_philosophers)
	{
		if (lunch->philo[i]->last_meal_ts != -1)
		{
			if ((get_timestamp() - lunch->philo[i]->last_meal_ts)
				> lunch->args.time_to_die)
			{
				print_state(lunch->philo[i], "died");
				set_printable(0, lunch);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	set_printable(int n, t_lunch *lunch)
{
	int		i;

	i = 0;
	while (i < lunch->args.total_philosophers)
	{
		lunch->philo[i]->is_printable = n;
		i++;
	}
}

int	is_printable(t_philo *philo)
{
	int	r;

	r = philo->is_printable;
	return (r);
}
