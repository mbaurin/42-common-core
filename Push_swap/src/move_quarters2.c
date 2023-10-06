/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_quarters2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:57:38 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/23 17:57:39 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_quarter_1(t_desk *desk)
{
	if (desk->b && desk->b->n > desk->quarter / 2)
		rb(desk);
	pb(desk);
}

void	move_quarter_2(t_desk *desk)
{
	if (desk->b && desk->b->n > (desk->median / 4) * 3)
		rb(desk);
	pb(desk);
}

void	move_quarter_3(t_desk *desk)
{
	if (desk->b && desk->b->n > (desk->median / 4) * 5)
		rb(desk);
	pb(desk);
}

void	move_quarter_4(t_desk *desk)
{
	if (desk->b && desk->b->n > (desk->median / 4) * 7)
		rb(desk);
	pb(desk);
}
