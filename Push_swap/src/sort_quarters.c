/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quarters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:54 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:56 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_and_push_to_a(t_desk *desk)
{
	if (desk->small_rotate_to_start >= 0)
		while (desk->small_rotate_to_start--)
			rb(desk);
	else if (desk->small_rotate_to_end >= 0)
		while (desk->small_rotate_to_end--)
			rrb(desk);
	else if (desk->big_rotate_to_start >= 0)
		while (desk->big_rotate_to_start--)
			rb(desk);
	else if (desk->big_rotate_to_end >= 0)
		while (desk->big_rotate_to_end--)
			rrb(desk);
	pa(desk);
	if (desk->small_flag)
		ra(desk);
	if (desk->big_flag || !desk->b)
		desk->after_rotate++;
	init_moves(desk);
}

void	push_big_small(t_desk *desk, t_stack *stack, t_stack *stack_end)
{
	while (1)
	{
		while (stack->n != desk->smallest && stack->n != desk->biggest)
			stack = stack->next;
		if (stack->n == desk->smallest || stack->n == desk->biggest)
		{
			rotate_and_push_to_a(desk);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = desk->b;
	}
}

void	sort_quarters(t_desk *desk)
{
	int	split;

	split = 1;
	median(desk, 'a');
	while (!sorted(desk))
	{
		move_quarters_handler(desk, desk->a, split);
		while (desk->b)
		{
			find_big_small(desk, 'b');
			moves_finder(desk, 'b');
			if (desk->b && (desk->small_rotate_to_start >= 0
					|| desk->small_rotate_to_end >= 0
					|| desk->big_rotate_to_start >= 0
					|| desk->big_rotate_to_end >= 0))
				push_big_small(desk, desk->b, desk->b->previous);
		}
		while (--desk->after_rotate)
			ra(desk);
		split++;
	}
}
