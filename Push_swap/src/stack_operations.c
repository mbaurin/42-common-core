/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:26:12 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:26:13 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	re_add_stack_top(t_desk *desk, t_stack **top, int num)
{
	t_stack		*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!(tmp))
		error(desk);
	tmp->next = *top;
	tmp->previous = (*top)->previous;
	(*top)->previous = tmp;
	tmp->previous->next = tmp;
	tmp->n = num;
	*top = (*top)->previous;
}

void	add_stack_top(t_desk *desk, char name, int num)
{
	t_stack		**top;

	if (name == 'a')
		top = &desk->a;
	else
		top = &desk->b;
	if (*top)
		re_add_stack_top(desk, top, num);
	else
	{
		*top = (t_stack *)malloc(sizeof(t_stack));
		if (!(*top))
			error(desk);
		(*top)->next = *top;
		(*top)->previous = *top;
		(*top)->n = num;
	}
}

void	re_add_stack_end(t_desk *desk, t_stack **top, int num)
{
	t_stack		*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!(tmp))
		error(desk);
	tmp->next = *top;
	tmp->previous = (*top)->previous;
	(*top)->previous = tmp;
	tmp->previous->next = tmp;
	tmp->n = num;
}

void	add_stack_end(t_desk *desk, char stack, int num)
{
	t_stack		**top;

	if (stack == 'a')
		top = &desk->a;
	else
		top = &desk->b;
	if (*top)
		re_add_stack_end(desk, top, num);
	else
	{
		*top = (t_stack *)malloc(sizeof(t_stack));
		if (!(*top))
			error(desk);
		(*top)->next = *top;
		(*top)->previous = *top;
		(*top)->n = num;
	}
}

void	delete_stack_top(t_desk *desk, char name)
{
	t_stack		**top;
	t_stack		*tmp;

	if (name == 'a')
		top = &desk->a;
	else
		top = &desk->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->previous->next = *top;
			(*top)->previous = tmp->previous;
			free(tmp);
		}
	}
}
