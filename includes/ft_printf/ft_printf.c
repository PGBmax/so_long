/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:34:10 by pboucher          #+#    #+#             */
/*   Updated: 2024/12/20 18:33:11 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list list, char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (str == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (str == 'p')
		count += ft_puthexa(va_arg(list, unsigned long));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(list, int), 0);
	else if (str == 'u')
		count += ft_putnbr(va_arg(list, unsigned int), 1);
	else if (str == 'x')
		count += ft_puthexa_uol(va_arg(list, unsigned int), 0);
	else if (str == 'X')
		count += ft_puthexa_uol(va_arg(list, unsigned int), 1);
	else if (str == '%')
		count += ft_putchar('%');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(str);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_format(list, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (count);
}
