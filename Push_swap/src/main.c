/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:16 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:17 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sorted(t_desk *desk)
{
	t_stack		*tmp;

	tmp = desk->a;
	while (tmp->next != desk->a)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_desk	*desk;

	desk = NULL;
	if (argc < 2)
		return (0);
	desk = generate_desk(desk, argv);
	get_stack_a(desk);
	if (!sorted(desk))
	{
		if (stack_len(desk, 'a') == 2)
			solve_2(desk);
		else if (stack_len(desk, 'a') == 3)
			solve_3(desk);
		else if (stack_len(desk, 'a') == 5)
			solve_5(desk);
		else if (stack_len(desk, 'a') <= 10)
			 sort_small(desk);
		else
			sort_quarters(desk);
	}
	free_all(desk);
	return (0);
}
