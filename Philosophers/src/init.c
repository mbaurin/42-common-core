/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:41:52 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:41:53 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_left_fork(t_philo *philo, t_lunch *lunch)
{
	philo->l_f = ft_safe_malloc(sizeof(pthread_mutex_t), lunch);
	pthread_mutex_init(philo->l_f, NULL);
}

t_philo	*create_philosopher(int id, t_lunch *lunch)
{
	t_philo	*philo;

	philo = ft_safe_malloc(sizeof(t_philo), lunch);
	philo->id = id;
	philo->nb_eat = lunch->args.number_of_times_each_philo_must_eat;
	philo->l_f = NULL;
	philo->r_f = NULL;
	philo->args = lunch->args;
	philo->last_meal_ts = -1;
	philo->is_printable = 1;
	create_left_fork(philo, lunch);
	return (philo);
}

void	create_all_philosophers(t_lunch *lunch)
{
	int	i;

	i = 0;
	lunch->philo = ft_safe_malloc(sizeof(t_philo *)
			* lunch->args.total_philosophers, lunch);
	while (i < lunch->args.total_philosophers)
	{
		lunch->philo[i] = create_philosopher(i, lunch);
		i++;
	}
}

t_lunch	*init_all_struct(int argc, char **argv)
{
	t_lunch	*lunch;

	lunch = NULL;
	lunch = ft_safe_malloc(sizeof(t_lunch), lunch);
	lunch->nb_ptr = 0;
	if (!parse_args(argc, argv, lunch))
		ft_error("Arguments Error\n", lunch);
	create_all_philosophers(lunch);
	link_all_right_forks(lunch);
	return (lunch);
}
