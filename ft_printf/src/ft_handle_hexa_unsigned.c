/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:20 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:22 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert_hexa_unsigned(unsigned int value, t_struct *s)
{
	unsigned long long	value_save;
	char				*str;
	int					count;

	str = 0;
	count = 0;
	value_save = value;
	if (value == 0)
	{
		str = ft_strdup("0");
		ft_add_to_garbage(str, s);
		return (str);
	}
	while (value != 0)
	{
		value /= 16;
		count++;
	}
	if (!(str = ft_safe_malloc(sizeof(char) * (count + 1), s)))
		return (0);
	str[count] = '\0';
	str = ft_decimal_to_hexadecimal(value_save, str, count);
	return (str);
}

int		ft_handle_hexa_unsigned(t_struct *s, va_list list)
{
	char			*hexa_unsigned;
	unsigned int	value;

	value = va_arg(list, unsigned int);
	hexa_unsigned = ft_convert_hexa_unsigned((unsigned long long)value, s);
	if (s->converter == 'x')
		hexa_unsigned = ft_str_tolower(hexa_unsigned);
	if (s->zero_fill == 1 && s->width > 0 && s->precision == -1)
		s->precision = s->width;
	s->next_fill_char = '0';
	if (s->precision != -1)
		hexa_unsigned = ft_gen_result(s, s->precision,
		(value == 0 && s->precision == 0 ? "" : hexa_unsigned), 0);
	s->next_fill_char = ' ';
	hexa_unsigned = ft_gen_result(s, s->width, hexa_unsigned,
		s->left_align);
	ft_putstr(hexa_unsigned);
	return (ft_strlen(hexa_unsigned));
}
