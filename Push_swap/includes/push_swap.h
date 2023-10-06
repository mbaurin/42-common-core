/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:54:25 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/24 17:54:26 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

typedef struct s_desk
{
	struct s_stack	*a;
	struct s_stack	*b;
	char			**argv;

	int				*array;
	int				*sorted;

	int				biggest;
	int				big_rotate_to_start;
	int				big_rotate_to_end;
	int				big_flag;

	int				smallest;
	int				small_rotate_to_start;
	int				small_rotate_to_end;
	int				small_flag;

	int				after_rotate;
	int				stack_len;

	long			median;
	long			quarter;
	long			three_quarters;
}					t_desk;

t_desk		*generate_desk(t_desk *desk, char **argv);
void		get_stack_a(t_desk *desk);

int			ft_isdigit(int c);
long		atoi_push_swap(t_desk *desk, const char *str);
int			stack_len(t_desk *desk, char name);
t_stack		*define_stack(t_desk *desk, char name, int flag);
void		test_int(t_desk *desk, int test_int_size);
void		error(t_desk *desk);
void		free_all(t_desk *desk);

int			sorted(t_desk *desk);

void		move_quarters_handler(t_desk *desk, t_stack *stack_a, int split);
void		push_big_small(t_desk *desk, t_stack *stack, t_stack *stack_end);

void		init_moves(t_desk *desk);
void		moves_bottom(t_desk *desk, char name, int flag);
void		moves_finder(t_desk *desk, char name);

void		find_small(t_desk *desk, char name);
void		find_big(t_desk *desk, char name);
void		find_big_small(t_desk *desk, char name);

void		add_stack_end(t_desk *desk, char stack, int num);
void		add_stack_top(t_desk *desk, char name, int num);
void		delete_stack_top(t_desk *desk, char name);

void		median(t_desk *desk, char name);
void		push_median(t_desk *desk, int split);

void		solve_2(t_desk *desk);
void		solve_3(t_desk *desk);
void		solve_5(t_desk *desk);
void		sort_small(t_desk *desk);
void		sort_quarters(t_desk *desk);

void		move_quarter_1(t_desk *desk);
void		move_quarter_2(t_desk *desk);
void		move_quarter_3(t_desk *desk);
void		move_quarter_4(t_desk *desk);

void		ra(t_desk *desk);
void		rra(t_desk *desk);
void		pa(t_desk *desk);
void		sa(t_desk *desk);
void		rb(t_desk *desk);
void		rrb(t_desk *desk);
void		pb(t_desk *desk);
void		sb(t_desk *desk);

#endif
