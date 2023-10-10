/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:42:02 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:42:03 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	parse_args(int argc, char **argv, t_lunch *lunch)
{
	if (argc == 5 || argc == 6)
	{
		if (full_digit(argv))
		{
			lunch->args.total_philosophers = ft_atoi(argv[1]);
			lunch->args.time_to_die = ft_atoi(argv[2]);
			lunch->args.time_to_eat = ft_atoi(argv[3]);
			lunch->args.time_to_sleep = ft_atoi(argv[4]);
			lunch->args.number_of_times_each_philo_must_eat = -1;
			if (argc == 6)
				lunch->args.number_of_times_each_philo_must_eat
					= ft_atoi(argv[5]);
			if (lunch->args.total_philosophers <= 0
				|| lunch->args.time_to_die <= 0
				|| lunch->args.time_to_eat <= 0
				|| lunch->args.time_to_sleep <= 0)
				return (0);
			return (1);
		}
	}
	return (0);
}

void	print_element_parsed(t_lunch *lunch)
{
	printf("total philosophers:%d\n", lunch->args.total_philosophers);
	printf("time to die:%d\n", lunch->args.time_to_die);
	printf("time to eat:%d\n", lunch->args.time_to_eat);
	printf("time to sleep:%d\n", lunch->args.time_to_sleep);
	printf("number of times each philo must eat:%d\n",
		lunch->args.number_of_times_each_philo_must_eat);
}

void	print_state(t_philo *philo, char *str)
{
	if (is_printable(philo))
	{
		printf("%ld %d %s\n", (get_timestamp()
				- philo->lunch_start_ts), philo->id, str);
	}
}
