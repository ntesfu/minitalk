/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:08:30 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/04 08:08:43 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <unistd.h>

typedef struct s_unsigned_dt
{
	int		len;
	int		base_n;
	char	*base;
	char	*sgn;
}	t_unsgn_dt;

int		ft_printf(const char *str, ...);
int		print_char(int c, int flags[]);
int		print_string(char *str, int flags[]);
int		print_signed_int(int num, int flags[]);
int		print_pointer(unsigned long long ptr, int flags[]);
int		print_unsigned_int(unsigned int num, int flags[], int base_n, int cap);
void	print_space(int *len, int width, char sp);
void	print_rev_number(long rev, int precision);
void	print_unsgn_num_recurse(int b_n, char *b, unsigned long long nb, int p);
void	print_unsgn_int_num_recurse(int b_n, char *b, unsigned int nbr, int p);
void	print_signed_num_recursive(long nbr, int precision);
char	*get_sign_char(char *sgn, int *len);

#endif
