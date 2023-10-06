/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:26:04 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:26:05 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_2(t_desk *desk)
{
	if (desk->a->n > desk->a->next->n)
		sa(desk);
}

void	solve_3(t_desk *desk)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	find_big_small(desk, 'a');
	moves_bottom(desk, 'a', 2);
	if (desk->big_rotate_to_end >= 1)
		while (desk->big_rotate_to_end-- > 1)
			rra(desk);
	stack_a = desk->a;
	tmp = desk->a->next;
	if (stack_a->n > tmp->n)
		sa(desk);
}

void	solve_5(t_desk *desk)
{
	t_stack	*stack_a_end;
	t_stack	*tmp;
	int		flag;

	flag = 0;
	stack_a_end = desk->a->previous;
	median(desk, 'a');
	while (flag != 1)
	{
		if (desk->a == stack_a_end)
			flag = 1;
		if (desk->a->n < desk->median)
			pb(desk);
		else
			ra(desk);
	}
	solve_3(desk);
	tmp = desk->b->next;
	if (desk->b->n < tmp->n)
		sb(desk);
	pa(desk);
	pa(desk);
}

void	sort_small(t_desk *desk)
{
	while (!sorted(desk))
	{
		while (!sorted(desk))
		{
			if (desk->a->n > desk->a->next->n)
			{
				sa(desk);
				pb(desk);
			}
			else
				pb(desk);
			if (desk->b->n < desk->b->previous->n)
				rb(desk);
			if (desk->a->n > desk->a->next->n)
				ra(desk);
		}
		while (desk->b != NULL)
		{
			pa(desk);
			if (desk->a->n > desk->a->next->n)
				sa(desk);
		}
	}
}
