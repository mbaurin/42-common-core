/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:57 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:58 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_init_attribut(const char *text, t_struct *s, int i)
{
	while (text[i] == '0' || text[i] == '-')
	{
		if (text[i] == '0')
			s->zero_fill = 1;
		if (text[i] == '-')
			s->left_align = 1;
		i++;
	}
	return (i);
}

int		ft_init_width(const char *text, t_struct *s, int i, va_list list)
{
	int		a;
	int		val;
	char	*t;

	a = i;
	if (text[i] == '*')
	{
		val = va_arg(list, int);
		s->width = val;
		i++;
	}
	else
	{
		while (ft_isdigit(text[i]))
			i++;
		if (a != i)
		{
			t = ft_substr(text, a, i);
			s->width = ft_atoi(t);
			ft_clean(t);
		}
	}
	s->left_align = (s->width < 0 ? 1 : s->left_align);
	if (s->width < 0)
	{
		s->width = -s->width;
	}
	return (i);
}

char	*ft_get_precision(int a, const char *text, t_struct *s, int i)
{
	char	*t;

	t = "";
	if (a != i)
	{
		t = ft_substr(text, a, i);
		s->precision = ft_atoi(t);
		ft_clean(t);
	}
	else
		s->precision = 0;
	return (t);
}

int		ft_init_precision(const char *text, t_struct *s, int i, va_list list)
{
	int a;
	int val;

	val = 0;
	if (text[i] == '.')
	{
		i++;
		a = i;
		if (text[i] == '*')
		{
			val = va_arg(list, int);
			s->precision = val;
			i++;
		}
		else
		{
			while (ft_isdigit(text[i]))
				i++;
			ft_get_precision(a, text, s, i);
		}
	}
	s->precision = (s->precision < 0 ? -1 : s->precision);
	return i;
}


int		ft_init_struct(t_struct *s, const char *text, int i, va_list list)
{
	i++;
	s->ptrs = NULL;
	s->zero_fill = 0;
	s->left_align = 0;
	s->width = 0;
	s->precision = 0;
	s->zero_char = 0;
	s->precision = -1;
	i = ft_init_attribut(text, s, i);
	i = ft_init_width(text, s, i, list);
	i = ft_init_precision(text, s, i, list);
	s->converter = text[i];
	if (s->left_align == 1)
		s->zero_fill = 0;
	i++;
	return (i);
}
