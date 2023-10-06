/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:25:05 by mbaurin           #+#    #+#             */
/*   Updated: 2021/09/21 19:25:07 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_doublon(t_desk *desk)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	tmp1 = desk->a;
	while (tmp1 != desk->a->previous)
	{
		tmp2 = tmp1->next;
		while (tmp2 != desk->a)
		{
			if (tmp1->n == tmp2->n)
				error(desk);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	fill_stack(t_desk *desk, char *str, int i)
{
	long int	test_int_size;
	int			j;

	j = 0;
	while (str)
	{
		while (*str)
		{
			j = 0;
			while (!j && *str && *str == ' ')
				str++;
			while ((str[j] && str[j] == '-') || str[j] == '+'
				|| ft_isdigit(str[j]))
				j++;
			if (!*str)
				break ;
			test_int_size = atoi_push_swap(desk, str);
			test_int(desk, test_int_size);
			add_stack_end(desk, 'a', test_int_size);
			str += j;
		}
		str = desk->argv[++i];
	}
	if (!desk->a)
		error(desk);
}

void	error_check(t_desk *desk)
{
	char	*str;
	int		i;

	i = 1;
	str = desk->argv[i];
	while (str)
	{
		while (*str)
		{
			if ((*str == ' ' || ft_isdigit(*str))
				|| (*str == '-' && ft_isdigit(*(str + 1))
					&& (str == desk->argv[i] || *(str - 1) == ' '))
				|| (*str == '+' && ft_isdigit(*(str + 1))
					&& (str == desk->argv[i] || *(str - 1) == ' ')))
				str++;
			else
				error(desk);
		}
		str = desk->argv[++i];
	}
}

void	check_empty_args(t_desk *desk)
{
	int	i;

	i = 0;
	while (desk->argv[i])
	{
		if (desk->argv[i][0] == '\0')
			error(desk);
		i++;
	}
}

void	get_stack_a(t_desk *desk)
{
	check_empty_args(desk);
	error_check(desk);
	fill_stack(desk, desk->argv[1], 1);
	check_doublon(desk);
}
