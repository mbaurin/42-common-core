/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:37:15 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:37:17 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		*ft_startstop(int word_size, int total_len, int left_allign,
t_struct *s)
{
	int		*stamp;

	stamp = ft_safe_malloc(sizeof(int) * 2, s);
	if (left_allign)
	{
		stamp[0] = 0;
		stamp[1] = word_size;
	}
	else
	{
		stamp[0] = total_len - word_size;
		stamp[1] = total_len;
	}
	return (stamp);
}

char	*ft_pre_fill(char c, int size, t_struct *s)
{
	char	*newtext;
	int		i;

	i = 0;
	newtext = ft_safe_malloc(sizeof(char) * (size + 1), s);
	newtext[size] = '\0';
	while (i < size)
	{
		newtext[i] = c;
		i++;
	}
	return (newtext);
}

char	*ft_gen_result(t_struct *s, int size, char *text,
int left_allign)
{
	char	*newtext;
	int		textlen;
	int		*ss;
	int		i;

	textlen = 0;
	i = 0;
	if (text != NULL)
	{
		textlen = ft_strlen(text);
		size = (size < textlen) ? textlen : size;
	}
	newtext = ft_pre_fill(s->next_fill_char, size, s);
	if (text != NULL)
	{
		ss = ft_startstop(textlen, size, left_allign, s);
		while (ss[0] < ss[1])
		{
			newtext[ss[0]] = text[i];
			ss[0]++;
			i++;
		}
	}
	return (newtext);
}
