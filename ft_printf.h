/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:52:25 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/20 15:36:49 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		print_param(char c, va_list arg);
int		print_char(char c);
int		print_str(char *s);
int		print_num(long i);
int		print_void(void *p);
void	print_hexa(unsigned long long n, int upper, int *i);

#endif