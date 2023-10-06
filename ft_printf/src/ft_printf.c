/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:37:03 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:37:04 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_assign_ft g_assign_ft[] = {
	{'c', &ft_handle_char},
	{'s', &ft_handle_string},
	{'p', &ft_handle_pointer},
	{'d', &ft_handle_signed_int},
	{'i', &ft_handle_signed_int},
	{'u', &ft_handle_unsigned_int},
	{'x', &ft_handle_hexa_unsigned},
	{'X', &ft_handle_hexa_unsigned},
	{'%', &ft_handle_char}
};

int		ft_get_result(t_struct *s, va_list l)
{
	int		i;

	i = 0;
	while (g_assign_ft[i].pf != NULL)
	{
		if (s->converter == g_assign_ft[i].converter)
			return (g_assign_ft[i].pf(s, l));
		i++;
	}
	return (0);
}

void	ft_total_clean(t_struct *s)
{
	ft_lstclear(&(s->ptrs), &ft_clean);
	ft_clean(s);
}

int		ft_printf(const char *text, ...)
{
	va_list		args;
	int			i;
	int			rv;
	t_struct	*s;

	i = 0;
	rv = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
		{
			s = ft_safe_malloc(sizeof(t_struct), NULL);
			i = ft_init_struct(s, text, i, args);
			rv += ft_get_result(s, args);
			ft_total_clean(s);
		}
		else
		{
			ft_putchar(text[i++]);
			rv++;
		}
	}
	va_end(args);
	return (rv);
}
