#include "../includes/cub3d.h"

void	ft_clean(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	ft_add_to_garbage(void *ptr, t_map *s)
{
	ft_lstadd_front(&(s->ptrs), ft_lstnew(ptr));
}

void	ft_total_clean(t_map *m)
{
	ft_lstclear(&(m->ptrs), &ft_clean);
	ft_clean(m->ptrs);
	ft_clean(m);
}

void	*ft_safe_malloc(unsigned int size, t_map *s)
{
	void	*ptr;

	ptr = (char *)malloc(size);
	if (!ptr)
	{
		send_error("Malloc error.", s);
		return (NULL);
	}
	if (s != NULL)
		ft_add_to_garbage(ptr, s);
	return (ptr);
}
