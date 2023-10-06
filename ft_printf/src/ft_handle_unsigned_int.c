/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:51 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:52 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			ft_conversion(t_struct *s, char *str, long nbr,
unsigned int nbrdigit)
{
	s->precision = s->precision;
	str[nbrdigit] = '\0';
	nbrdigit = nbrdigit - 1;
	str[nbrdigit] = nbr % 10 + '0';
	nbr = nbr / 10;
	while (nbr > 0)
	{
		nbrdigit = nbrdigit - 1;
		str[nbrdigit] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
}

static unsigned int	ft_getdigit(long nbr)
{
	unsigned int	nbrdigit;

	if (nbr == 0)
		return (1);
	nbrdigit = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		nbrdigit++;
	}
	return (nbrdigit);
}

char				*ft_itoa_u(unsigned int n, t_struct *s)
{
	unsigned int	nbrdigit;
	unsigned int	nbr;
	char			*str;

	nbr = n;
	nbrdigit = ft_getdigit(nbr);
	if (!(str = ft_safe_malloc(sizeof(char) * (nbrdigit + 1), s)))
		return (NULL);
	if (s->precision != -1 && nbr == 0)
		str[0] = '\0';
	else if (nbr == 0)
	{
		str = ft_strdup("0");
		ft_add_to_garbage(str, s);
	}
	else
		ft_conversion(s, str, nbr, nbrdigit);
	return (str);
}

int					ft_handle_unsigned_int(t_struct *s, va_list list)
{
	char	*str;
	int		val;

	str = NULL;
	val = va_arg(list, int);
	str = ft_itoa_u(val, s);
	if (s->zero_fill == 1 && s->width > 0 && s->precision == -1)
		s->precision = s->width;
	if (s->precision != -1)
	{
		if (s->precision < (int)ft_strlen(str))
			s->precision = ft_strlen(str);
		s->next_fill_char = '0';
		str = ft_gen_result(s, s->precision,
		(val == 0 && s->precision == 0 ? "" : str), 0);
	}
	s->next_fill_char = ' ';
	str = ft_gen_result(s, s->width, str, s->left_align);
	ft_putstr(str);
	return (ft_strlen(str));
}
