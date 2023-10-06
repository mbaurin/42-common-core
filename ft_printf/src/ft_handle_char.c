/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:14 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:16 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_c_to_str(char c, t_struct *s)
{
	char	*sp;

	sp = ft_safe_malloc(2 * sizeof(char), s);
	sp[0] = c;
	sp[1] = '\0';
	return (sp);
}

char	*ft_handle_special_case_char(int val, t_struct *s, char *result)
{
	if (val == 0)
	{
		s->zero_char = 1;
		s->width--;
		if (s->left_align)
		{
			ft_putchar('\0');
			result = ft_gen_result(s, s->width, NULL, s->left_align);
			ft_putstr(result);
		}
		else
		{
			result = ft_gen_result(s, s->width, NULL, s->left_align);
			ft_putstr(result);
			ft_putchar('\0');
		}
	}
	else
	{
		result = ft_gen_result(s, s->width, ft_c_to_str(val, s),
		s->left_align);
		ft_putstr(result);
	}
	return (result);
}

int		ft_handle_char(t_struct *s, va_list list)
{
	int		val;
	char	*result;
	int		rv;

	result = "";
	s->next_fill_char = (s->zero_fill == 0 ? ' ' : '0');
	if (s->converter == '%')
		val = '%';
	else
		val = va_arg(list, int);
	result = ft_handle_special_case_char(val, s, result);
	rv = ft_strlen(result) + s->zero_char;
	return (rv);
}
