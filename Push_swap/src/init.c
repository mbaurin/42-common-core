/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:11 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:12 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_desk	*generate_desk(t_desk *desk, char **argv)
{
	desk = (t_desk *)malloc(sizeof(t_desk));
	if (!(desk))
		exit(1);
	desk->a = NULL;
	desk->b = NULL;
	desk->argv = argv;
	desk->biggest = 0;
	desk->big_rotate_to_start = 0;
	desk->big_rotate_to_end = 0;
	desk->big_flag = 0;
	desk->smallest = 0;
	desk->small_rotate_to_start = 0;
	desk->small_rotate_to_end = 0;
	desk->small_flag = 0;
	desk->after_rotate = 0;
	desk->stack_len = 0;
	desk->median = 0;
	desk->quarter = 0;
	desk->three_quarters = 0;
	return (desk);
}

void	init_moves(t_desk *desk)
{
	desk->biggest = 0;
	desk->big_rotate_to_start = 0;
	desk->big_rotate_to_end = 0;
	desk->big_flag = 0;
	desk->smallest = 0;
	desk->small_rotate_to_start = 0;
	desk->small_rotate_to_end = 0;
	desk->small_flag = 0;
}
