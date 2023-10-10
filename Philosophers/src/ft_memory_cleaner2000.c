/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_cleaner2000.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:41:46 by mbaurin           #+#    #+#             */
/*   Updated: 2022/01/11 18:41:47 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_clean(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_add_to_garbage(void *ptr, t_lunch *s)
{
	s->nb_ptr++;
	ft_lstadd_front(&(s->ptrs), ft_lstnew(ptr));
}

void	ft_total_clean(t_lunch *m)
{
	ft_lstclear(&(m->ptrs), &ft_clean, m);
	ft_clean(m->ptrs);
	ft_clean(m);
}

void	*ft_safe_malloc(unsigned int size, t_lunch *s)
{
	void	*ptr;

	ptr = (char *)malloc(size);
	if (!ptr)
	{
		printf("Malloc error\n");
		exit(0);
		return (NULL);
	}
	if (s != NULL)
		ft_add_to_garbage(ptr, s);
	return (ptr);
}
