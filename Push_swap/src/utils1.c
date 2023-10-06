/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:26:19 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:26:20 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	atoi_push_swap(t_desk *desk, const char *str)
{
	unsigned int	i;
	long			moins;
	long			res;
	int				len;

	i = 0;
	moins = 1;
	res = 0;
	len = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			moins = -1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		len++;
	}
	if (len > 10)
		error(desk);
	return (res * moins);
}

int	stack_len(t_desk *desk, char name)
{
	t_stack	*stack;
	t_stack	*end;
	int		len;

	if (name == 'a')
	{
		stack = desk->a;
		end = desk->a->previous;
	}
	else
	{
		stack = desk->b;
		end = desk->b->previous;
	}
	len = 0;
	while (stack)
	{
		len++;
		if (stack == end)
			break ;
		stack = stack->next;
	}
	return (len);
}

t_stack	*define_stack(t_desk *desk, char name, int flag)
{
	t_stack	*tmp;

	if (flag == 2)
	{
		if (name == 'a')
			tmp = desk->a;
		else
			tmp = desk->b;
	}
	else
	{
		if (name == 'a')
			tmp = desk->a->previous;
		else
			tmp = desk->b->previous;
	}
	return (tmp);
}

void	test_int(t_desk *desk, int test_int_size)
{
	if (test_int_size > 2147483647 || test_int_size < -2147483648)
		error(desk);
}

void	error(t_desk *desk)
{
	desk = NULL;
	write(2, "Error\n", 6);
	exit(-1);
}
