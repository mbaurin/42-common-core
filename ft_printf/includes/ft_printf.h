/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaurin <mbaurin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 07:37:09 by mbaurin           #+#    #+#             */
/*   Updated: 2021/02/25 07:37:10 by mbaurin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/includes/libft.h"

typedef	struct
{
	int		zero_fill;
	int		left_align;
	int		width;
	int		precision;
	char	converter;
	char	zero_char;
	char	next_fill_char;
	t_list	*ptrs;
}			t_struct;

typedef	struct
{
	char	converter;
	int		(*pf)(t_struct*, va_list);
}			t_assign_ft;

int			ft_printf(const char *text
, ...) __attribute__((format(printf,1,2)));
int			ft_get_result(t_struct *s, va_list l);
void		ft_total_clean(t_struct *s);

int			ft_init_struct(t_struct *s, const char *text, int i, va_list list);
int			ft_init_precision(const char *text, t_struct *s,
int i, va_list list);
char		*ft_get_precision(int a, const char *text, t_struct *s, int i);
int			ft_init_width(const char *text, t_struct *s, int i, va_list list);
int			ft_init_attribut(const char *text, t_struct *s, int i);

int			ft_handle_char(t_struct *s, va_list list);
char		*ft_handle_special_case_char(int val, t_struct *s, char *result);
char		*ft_c_to_str(char c, t_struct *s);

void		ft_clean(void *ptr);
void		*ft_safe_malloc(unsigned int size, t_struct *s);
void		ft_add_to_garbage(void *ptr, t_struct *s);

void		ft_clean_all(t_struct *s);

int			*ft_startstop(int word_size, int total_len, int left_allign,
t_struct *s);
char		*ft_pre_fill(char c, int size, t_struct *s);
char		*ft_gen_result(t_struct *s, int size, char *text,
int left_allign);

int			ft_handle_hexa_unsigned(t_struct *s, va_list list);
char		*ft_convert_hexa_unsigned(unsigned int value, t_struct *s);

int			ft_handle_unsigned_int(t_struct *s, va_list list);
char		*ft_itoa_u(unsigned int n, t_struct *s);

char		*ft_str_tolower(char *str);
char		*ft_decimal_to_hexadecimal(unsigned long long value, char *str,
int count);
int			ft_handle_pointer(t_struct *s, va_list list);
char		*add_pattern(char *ptr, t_struct *s);
char		*ft_convert_pointer(unsigned long long value, t_struct *s);

int			ft_handle_string(t_struct *s, va_list list);
char		*ft_handle_special_case_string(char *value, t_struct *s, char *str);
char		*ft_handle_string_value(char *value, t_struct *s, char *str);

int			ft_handle_signed_int(t_struct *s, va_list list);
char		*ft_handle_special_case_signed_int(int neg, char *str, int val,
t_struct *s);
char		*ft_add_minus(char *text, t_struct *s);

#endif
