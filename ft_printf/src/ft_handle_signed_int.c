/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signed_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:37 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:38 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_minus(char *text, t_struct *s)
{
	char	*new_text;
	int		i;
	int		already_min;

	new_text = ft_safe_malloc(sizeof(char) * (ft_strlen(text) + 2), s);
	already_min = 0;
	i = 0;
	if (text[0] == '-')
	{
		i = 0;
		already_min = 1;
	}
	new_text[0] = '-';
	while (text[i])
	{
		new_text[i + 1] = text[i + already_min];
		i++;
	}
	new_text[i + 1] = '\0';
	return (new_text);
}

char	*ft_handle_special_case_signed_int(int neg, char *str, int val,
t_struct *s)
{
	str = ft_itoa(val);
	ft_add_to_garbage(str, s);
	if (neg && s->precision < (int)ft_strlen(str))
		s->precision = ft_strlen(str);
	s->next_fill_char = '0';
	str = ft_gen_result(s, s->precision,
	(val == 0 && s->precision == 0 ? "" : str), 0);
	str = (neg) ? ft_add_minus(str, s) : str;
	return (str);
}

int		ft_handle_signed_int(t_struct *s, va_list list)
{
	char	*str;
	int		val;
	int		neg;

	val = va_arg(list, int);
	neg = 0;
	str = ft_itoa(val);
	ft_add_to_garbage(str, s);
	neg = (val < 0) ? 1 : neg;
	if (s->zero_fill == 1 && s->width > 0 && s->precision == -1)
		s->precision = s->width - neg;
	if (s->precision != -1)
	{
		val = (val < 0) ? val * -1 : val;
		str = ft_handle_special_case_signed_int(neg, str, val, s);
	}
	s->next_fill_char = ' ';
	str = ft_gen_result(s, s->width, str, s->left_align);
	ft_putstr(str);
	return (ft_strlen(str));
}
