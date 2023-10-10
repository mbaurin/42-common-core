/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:41:56 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:41:58 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	link_right_fork(t_philo *philo, t_lunch *lunch)
{
	int	right_fork_id;

	right_fork_id = 0;
	if (philo->id < lunch->args.total_philosophers - 1)
		right_fork_id = philo->id + 1;
	philo->r_f = (pthread_mutex_t *)(lunch->philo[right_fork_id]->l_f);
}

void	link_all_right_forks(t_lunch *lunch)
{
	int	i;

	i = 0;
	while (i < lunch->args.total_philosophers)
	{
		link_right_fork(lunch->philo[i], lunch);
		i++;
	}
}

void	start_philo_routine(t_philo *philo)
{
	pthread_create(&(philo->thread), NULL, &routine, (void *)philo);
}

void	start_all_philo_routine(t_lunch *lunch)
{
	long int	dd;
	int			i;

	i = 0;
	while (i < lunch->args.total_philosophers)
	{
		start_philo_routine(lunch->philo[i]);
		i++;
	}
	i = 0;
	dd = get_timestamp();
	while (i < lunch->args.total_philosophers)
	{
		lunch->philo[i]->lunch_start_ts = dd;
		lunch->philo[i]->last_meal_ts = dd;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_lunch	*lunch;

	lunch = init_all_struct(argc, argv);
	start_all_philo_routine(lunch);
	while (1)
	{
		if (is_someone_died(lunch))
		{
			printf("The meal is over because a philosopher died\n");
			break ;
		}
		if (is_all_finish(lunch))
		{
			printf("The meal is over, all the philosophers ate %d times\n",
				lunch->args.number_of_times_each_philo_must_eat);
			break ;
		}
	}
	ft_total_clean(lunch);
}
