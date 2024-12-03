/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:52:25 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/03 10:04:02 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		print_param(char c, va_list arg);
int		print_char(char c);
int		print_str(char *s);
int		print_int(int i);
int		print_void(void *p);
int		print_undec(unsigned int i);
void	print_hexa(unsigned int n, int upper, int *i);
void	print_hexa_ull(unsigned long long n, int upper, int *i);

#endif