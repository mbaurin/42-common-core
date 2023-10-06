/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:47 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:49 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_desk *desk)
{
	if (desk->a)
		desk->a = desk->a->next;
	write(1, "ra\n", 3);
}

void	rb(t_desk *desk)
{
	if (desk->b)
		desk->b = desk->b->next;
	write(1, "rb\n", 3);
}

void	rra(t_desk *desk)
{
	if (desk->a)
		desk->a = desk->a->previous;
	write(1, "rra\n", 4);
}

void	rrb(t_desk *desk)
{
	if (desk->b)
		desk->b = desk->b->previous;
	write(1, "rrb\n", 4);
}
