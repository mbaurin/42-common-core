/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:26:25 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:26:26 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_desk *desk)
{
	long int	tmp;

	if (desk->a && desk->a->next != desk->a)
	{
		tmp = desk->a->n;
		desk->a->n = desk->a->next->n;
		desk->a->next->n = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_desk *desk)
{
	long int	tmp;

	if (desk->b && desk->b->next != desk->b)
	{
		tmp = desk->b->n;
		desk->b->n = desk->b->next->n;
		desk->b->next->n = tmp;
	}
	write(1, "sb\n", 3);
}
