/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:22:17 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/20 15:22:15 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	ull_to_hexa(unsigned long long i)
{
	return ("0123456789abcdef"[i % 16]);
}

void	print_hexa(unsigned long long n, int upper, int *i)
{
	int	byte;

	if (n >= 16)
	{
		(*i)++;
		print_hexa(n / 16, upper, i);
	}
	if (upper >= 1)
		byte = print_char(ft_toupper(ull_to_hexa(n)));
	else
		byte = print_char(ull_to_hexa(n));
	if (byte == -1)
	{
		*i = -1;
		return ;
	}
}

int	print_void(void *p)
{
	int	i;

	if (p == NULL)
		return (print_str("(nil)"));
	i = 1;
	i += print_str("0x");
	print_hexa((unsigned long long)p, 0, &i);
	return (i);
}
