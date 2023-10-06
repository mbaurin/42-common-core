/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:36:26 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:36:27 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_clean(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_add_to_garbage(void *ptr, t_struct *s)
{
	ft_lstadd_back(&(s->ptrs), ft_lstnew(ptr));
}

void	*ft_safe_malloc(unsigned int size, t_struct *s)
{
	void	*ptr;

	if (!(ptr = (char *)malloc(size)))
		return (NULL);
	if (s != NULL)
		ft_add_to_garbage(ptr, s);
	return (ptr);
}
