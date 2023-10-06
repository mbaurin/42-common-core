/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:08:00 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/23 16:08:01 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack		*next;
	t_stack		*delete;

	if (stack)
	{
		next = stack->next;
		while (next != stack)
		{
			delete = next;
			next = next->next;
			free(delete);
		}
		free(next);
	}
}

void	free_all(t_desk *desk)
{
	if (desk)
	{
		if (desk->a)
			free_stack(desk->a);
		if (desk->b)
			free_stack(desk->b);
		free(desk);
	}
}
