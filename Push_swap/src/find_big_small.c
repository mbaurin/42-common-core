/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_big_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:24:59 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:00 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_big(t_desk *desk, char name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	if (name == 'a')
		stack = desk->a;
	else
		stack = desk->b;
	tmp = stack;
	desk->biggest = tmp->n;
	if (name == 'a')
		end = desk->a->previous;
	else
		end = desk->b->previous;
	while (1)
	{
		if (tmp->n > desk->biggest)
			desk->biggest = tmp->n;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_small(t_desk *desk, char name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	if (name == 'a')
		stack = desk->a;
	else
		stack = desk->b;
	tmp = stack;
	if (name == 'a')
		end = desk->a->previous;
	else
		end = desk->b->previous;
	desk->smallest = desk->biggest;
	while (1)
	{
		if (tmp->n <= desk->smallest)
			desk->smallest = tmp->n;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_big_small(t_desk *desk, char name)
{
	t_stack		*stack;

	if (name == 'a')
		stack = desk->a;
	else
		stack = desk->b;
	find_big(desk, name);
	find_small(desk, name);
}
