/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:41 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:42 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_desk *desk)
{
	long int	tmp;

	if (desk->b)
	{
		tmp = desk->b->n;
		delete_stack_top(desk, 'b');
		add_stack_top(desk, 'a', tmp);
	}
	write(1, "pa\n", 3);
}

void	pb(t_desk *desk)
{
	long int	tmp;

	if (desk->a)
	{
		tmp = desk->a->n;
		delete_stack_top(desk, 'a');
		add_stack_top(desk, 'b', tmp);
	}
	write(1, "pb\n", 3);
}
