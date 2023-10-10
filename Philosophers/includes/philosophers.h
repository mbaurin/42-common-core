/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:56:31 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:56:32 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdarg.h>
# include <pthread.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_arg
{
	int			total_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philo_must_eat;
}				t_arg;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*r_f;
	pthread_mutex_t		*l_f;
	long int			lunch_start_ts;
	long int			last_meal_ts;
	int					nb_eat;
	int					is_printable;
	t_arg				args;
}						t_philo;

typedef struct s_lunch
{
	t_philo					**philo;
	t_arg					args;
	t_list					*ptrs;
	long int				start_ts;
	int						nb_p_finish;
	int						stop;
	int						nb_ptr;
}							t_lunch;

void	*ft_safe_malloc(unsigned int size, t_lunch *s);
void	ft_total_clean(t_lunch *m);
void	ft_add_to_garbage(void *ptr, t_lunch *s);
void	ft_clean(void *ptr);

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*), t_lunch *m);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lts, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

void	ft_error(char *str, t_lunch *lunch);
int		ft_atoi(char *str);
int		full_digit(char **str);
long	get_timestamp(void);

void	ft_usleep(long int time_in_ms);
int		get_forks(t_philo *philo);
void	eat(t_philo *philo);
void	dodo(t_philo *philo);
void	*routine(void *ptr);

int		is_all_finish(t_lunch *lunch);
int		is_someone_died(t_lunch *lunch);
void	set_printable(int n, t_lunch *lunch);
int		is_printable(t_philo *philo);

t_philo	*create_philosopher(int id, t_lunch *all_philo);
void	create_all_philosophers(t_lunch *lunch);

void	print_state(t_philo *philo, char *str);
t_lunch	*init_all_struct(int argc, char **argv);

int		parse_args(int argc, char **argv, t_lunch *lunch);
void	print_element_parsed(t_lunch *lunch);

void	link_all_right_forks(t_lunch *lunch);

#endif
