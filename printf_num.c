/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:52:03 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/20 15:49:13 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	putnbr(long n, int *count)
{
	int		byte;

	byte = 0;
	if (n < 0)
	{
		byte = print_char('-');
		n *= -1;
		(*count)++;
	}
	if (n >= 10 && byte != -1)
	{
		(*count)++;
		putnbr(n / 10, count);
	}
	if (byte != -1)
		byte = print_char('0' + n % 10);
	if (byte == -1)
	{
		*count = -1;
		return ;
	}
}

int	print_num(long i)
{
	int	count;

	count = 1;
	putnbr(i, &count);
	return (count);
}
