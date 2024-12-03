/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edarnand <edarnand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:26:15 by edarnand          #+#    #+#             */
/*   Updated: 2024/12/03 10:23:22 by edarnand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_char(char c)
{
	int	byte;

	byte = write(1, &c, 1);
	if (byte == 1)
		return (1);
	else
		return (-1);
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
