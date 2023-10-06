/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:31 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:33 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

char	*ft_decimal_to_hexadecimal(unsigned long long value, char *str,
int count)
{
	while (value != 0)
	{
		if ((value % 16) < 10)
			str[count - 1] = (value % 16) + 48;
		else
			str[count - 1] = (value % 16) + 55;
		value /= 16;
		count--;
	}
	return (str);
}

char	*ft_convert_pointer(unsigned long long value, t_struct *s)
{
	char				*str;
	int					count;
	unsigned long long	value_save;

	str = 0;
	count = 0;
	value_save = value;
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

char	*add_pattern(char *ptr, t_struct *s)
{
	char	*newtext;
	int		i;
	int		size;

	size = (ptr == NULL ? 0 : ft_strlen(ptr));
	i = 2;
	s->next_fill_char = '0';
	if (s->precision)
		ptr = ft_gen_result(s, s->precision, ptr, 0);
	newtext = ft_safe_malloc(size * (sizeof(char) + 3), s);
	if (ptr != NULL)
	{
		while (i < (int)ft_strlen(ptr) + 2)
		{
			newtext[i] = ptr[i - 2];
			i++;
		}
	}
	newtext[0] = '0';
	newtext[1] = 'x';
	newtext[i] = '\0';
	return (newtext);
}

int		ft_handle_pointer(t_struct *s, va_list list)
{
	unsigned long long	value;
	char				*pointer;

	pointer = NULL;
	value = va_arg(list, unsigned long long);
	if (value != 0)
	{
		pointer = ft_convert_pointer(value, s);
		pointer = ft_str_tolower(pointer);
	}
	else if (s->precision == -1)
	{
		pointer = ft_strdup("0");
		ft_add_to_garbage(pointer, s);
	}
	pointer = add_pattern(pointer, s);
	s->next_fill_char = (s->zero_fill == 0 ? ' ' : '0');
	pointer = ft_gen_result(s, s->width, pointer, s->left_align);
	ft_putstr(pointer);
	return (ft_strlen(pointer));
}
