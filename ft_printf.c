/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:51:37 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/02 17:57:07 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		total;
	int		byte;

	total = 0;
	byte = 0;
	va_start(arg, s);
	while (*s != '\0')
	{
		if (*s == '%' && *(s + 1) != '\0')
		{
			s++;
			byte = print_param(*s, arg);
		}
		else
			byte = print_char(*s);
		if (byte == -1)
			return (-1);
		total += byte;
		s++;
	}
	va_end(arg);
	return (total);
}

int	print_param(char c, va_list arg)
{
	int	i;

	if (c == 'c')
		return (print_char(va_arg(arg, int)));
	if (c == 's')
		return (print_str(va_arg(arg, char *)));
	if (c == 'p')
		return (print_void(va_arg(arg, void *)));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(arg, int)));
	if (c == 'u')
		return (print_undec(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
	{
		i = 1;
		print_hexa(va_arg(arg, int), 'X' - c + 1, &i);
		return (i);
	}
	if (c == '%')
		return (print_char('%'));
	return (-1);
}
