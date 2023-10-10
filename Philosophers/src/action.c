/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:41:37 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:41:38 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	get_one_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_state(philo, "has taken a fork");
}

int	get_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		get_one_fork(philo, philo->r_f);
		get_one_fork(philo, philo->l_f);
	}
	else
	{
		get_one_fork(philo, philo->l_f);
		get_one_fork(philo, philo->r_f);
	}
	return (1);
}

void	eat(t_philo *philo)
{
	print_state(philo, "is eating");
	if (philo->args.number_of_times_each_philo_must_eat != -1)
		philo->nb_eat--;
	philo->last_meal_ts = get_timestamp();
	ft_usleep(philo->args.time_to_eat);
}

void	dodo(t_philo *philo)
{
	pthread_mutex_unlock((pthread_mutex_t *)philo->r_f);
	pthread_mutex_unlock((pthread_mutex_t *)philo->l_f);
	print_state(philo, "is sleeping");
	ft_usleep(philo->args.time_to_sleep + 1);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (philo->last_meal_ts == -1)
		;
	while (philo->is_printable)
	{
		if (philo->args.number_of_times_each_philo_must_eat == -1
			|| philo->nb_eat > 0)
		{
			get_forks(philo);
			eat(philo);
			dodo(philo);
			print_state(philo, "is thinking");
		}
	}
	return (ptr);
}
