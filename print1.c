/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:52:03 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/03 09:56:33 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	putnbr(int n, int *count)
{
	long int	i;
	int			byte;

	i = n;
	byte = 0;
	if (n < 0)
	{
		byte = print_char('-');
		i *= -1;
		(*count)++;
		if (byte == -1)
			*count = -1;
	}
	if (i > 9 && byte != -1)
	{
		(*count)++;
		putnbr(i / 10, count);
	}
	if (byte != -1)
		byte = print_char('0' + i % 10);
	if (byte == -1)
	{
		*count = -1;
		return ;
	}
}

int	print_str(char *s)
{
	int	len;
	int	byte;

	if (s == NULL)
		return (print_str("(null)"));
	len = ft_strlen(s);
	byte = write(1, s, len);
	if (byte != len)
		return (-1);
	return (len);
}

int	print_int(int i)
{
	int	count;

	count = 1;
	putnbr(i, &count);
	return (count);
}

static void	putnbr_un(unsigned int n, int *count)
{
	int	byte;

	if (n > 9)
	{
		(*count)++;
		putnbr_un(n / 10, count);
	}
	byte = print_char('0' + n % 10);
	if (byte == -1)
	{
		*count = -1;
		return ;
	}
}

int	print_undec(unsigned int i)
{
	int	count;

	count = 1;
	putnbr_un(i, &count);
	return (count);
}
