/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_quarters1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:57:33 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/23 17:57:34 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_horrible_normi(t_stack *stack_a, t_stack *stack_a_end)
{
	int	stop;

	stop = 0;
	if (stack_a == stack_a_end)
		stop = 1;
	return (stop);
}

void	move_quarters(t_desk *desk, t_stack *stack_a, t_stack *stack_a_end,
	int split)
{
	int		stop;

	stop = 0;
	while (stop != 1)
	{
		stop = check_horrible_normi(stack_a, stack_a_end);
		if (split == 1 && stack_a->n <= desk->quarter)
			move_quarter_1(desk);
		else if (split == 2 && stack_a->n > desk->quarter
			&& stack_a->n <= desk->median)
			move_quarter_2(desk);
		else if (split == 3 && stack_a->n > desk->median
			&& stack_a->n <= desk->three_quarters)
			move_quarter_3(desk);
		else if (split == 4 && stack_a->n > desk->three_quarters)
			move_quarter_4(desk);
		else if (split == 4 && stack_a->n == desk->smallest)
			break ;
		else
			ra(desk);
		stack_a = desk->a;
	}
}

void	move_quarters_handler(t_desk *desk, t_stack *stack_a, int split)
{
	t_stack	*stack_a_end;

	stack_a_end = desk->a->previous;
	find_big_small(desk, 'a');
	move_quarters(desk, stack_a, stack_a_end, split);
	init_moves(desk);
}
