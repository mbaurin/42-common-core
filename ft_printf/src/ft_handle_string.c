/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:43 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:44 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_handle_string_value(char *value, t_struct *s, char *str)
{
	if (value == NULL)
	{
		str = ft_strdup("(null)");
		ft_add_to_garbage(str, s);
	}
	else
	{
		str = ft_strdup(value);
		ft_add_to_garbage(str, s);
	}
	return (str);
}

char	*ft_handle_special_case_string(char *value, t_struct *s, char *str)
{
	str = ft_handle_string_value(value, s, str);
	if (str == 0)
	{
		s->zero_char = 1;
		s->width--;
		ft_putchar('0');
		s->next_fill_char = (s->zero_fill == 0 ? ' ' : '0');
		str = ft_gen_result(s, s->width, str, s->left_align);
	}
	else
	{
		if (s->precision < (int)ft_strlen(str))
			str[s->precision] = '\0';
		s->next_fill_char = (s->zero_fill == 0 ? ' ' : '0');
		str = ft_gen_result(s, s->width, str, s->left_align);
	}
	return (str);
}

int		ft_handle_string(t_struct *s, va_list list)
{
	char	*value;
	char	*str;
	int		rv;

	str = "";
	value = va_arg(list, char*);
	str = ft_handle_special_case_string(value, s, str);
	ft_putstr(str);
	rv = ft_strlen(str) + s->zero_char;
	return (rv);
}
