/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:21 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:22 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_array(long *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

void	find_median(t_desk *desk, t_stack *stack, char name)
{
	long	*array;
	int		i;
	int		quarter_len;

	i = 0;
	desk->stack_len = stack_len(desk, name);
	quarter_len = desk->stack_len / 4;
	array = (long *)malloc(sizeof(long) * (desk->stack_len + 1));
	if (!(array))
		error(desk);
	while (i < desk->stack_len)
	{
		array[i++] = stack->n;
		stack = stack->next;
	}
	sort_array(array, desk->stack_len);
	desk->quarter = array[quarter_len];
	desk->median = array[quarter_len * 2];
	desk->three_quarters = array[quarter_len * 3];
	free(array);
}

void	median(t_desk *desk, char name)
{
	t_stack	*stack;

	if (name == 'a')
		stack = desk->a;
	else
		stack = desk->b;
	find_median(desk, stack, name);
}
