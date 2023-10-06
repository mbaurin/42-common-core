/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:31 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:33 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	moves_top(t_desk *desk, char name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = define_stack(desk, name, 2);
	if (stack)
	{
		tmp = define_stack(desk, name, 2);
		if (flag == 1)
			element = desk->smallest;
		else
			element = desk->biggest;
		while (tmp->n != element)
		{
			if (flag == 1)
				desk->small_rotate_to_start++;
			else
				desk->big_rotate_to_start++;
			tmp = tmp->next;
		}
	}
}

void	moves_bottom(t_desk *desk, char name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = define_stack(desk, name, 2);
	if (stack)
	{
		tmp = define_stack(desk, name, 1);
		if (flag == 1)
			element = desk->smallest;
		else
			element = desk->biggest;
		while (tmp->n != element)
		{
			if (flag == 1)
				desk->small_rotate_to_end++;
			else
				desk->big_rotate_to_end++;
			tmp = tmp->previous;
		}
		if (flag == 1)
			desk->small_rotate_to_end++;
		else
			desk->big_rotate_to_end++;
	}
}

void	moves_smallest(t_desk *desk, char name)
{
	t_stack	*stack;
	int		flag;

	stack = define_stack(desk, name, 2);
	flag = 1;
	if (stack)
	{
		moves_top(desk, name, flag);
		moves_bottom(desk, name, flag);
		if (desk->small_rotate_to_start <= desk->small_rotate_to_end)
			desk->small_rotate_to_end = -1;
		else
			desk->small_rotate_to_start = -1;
	}
}

void	moves_biggest(t_desk *desk, char name)
{
	t_stack	*stack;
	int		flag;

	stack = define_stack(desk, name, 2);
	flag = 2;
	if (stack)
	{
		moves_top(desk, name, flag);
		moves_bottom(desk, name, flag);
		if (desk->big_rotate_to_start <= desk->big_rotate_to_end)
			desk->big_rotate_to_end = -1;
		else
			desk->big_rotate_to_start = -1;
	}
}

void	moves_finder(t_desk *desk, char name)
{
	t_stack	*stack;

	stack = define_stack(desk, name, 2);
	moves_smallest(desk, 'b');
	moves_biggest(desk, 'b');
	if (desk->big_rotate_to_start != -1 && (desk->big_rotate_to_start
			>= desk->small_rotate_to_start && desk->big_rotate_to_start
			>= desk->small_rotate_to_end))
		desk->big_rotate_to_start = -1;
	else if (desk->big_rotate_to_end != -1 && (desk->big_rotate_to_end
			>= desk->small_rotate_to_start && desk->big_rotate_to_end
			>= desk->small_rotate_to_end))
		desk->big_rotate_to_end = -1;
	else if (desk->small_rotate_to_start != -1 && (desk->small_rotate_to_start
			>= desk->big_rotate_to_start && desk->small_rotate_to_start
			>= desk->big_rotate_to_end))
		desk->small_rotate_to_start = -1;
	else if (desk->small_rotate_to_end != -1 && (desk->small_rotate_to_end
			>= desk->big_rotate_to_start && desk->small_rotate_to_end
			>= desk->big_rotate_to_end))
		desk->small_rotate_to_end = -1;
	if (desk->small_rotate_to_start != -1 || desk->small_rotate_to_end != -1)
		desk->small_flag = 1;
	else if (desk->big_rotate_to_start != -1 || desk->big_rotate_to_end != -1)
		desk->big_flag = 1;
}
