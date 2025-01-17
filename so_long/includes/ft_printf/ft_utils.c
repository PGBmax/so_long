/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:44:55 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/14 23:55:39 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

int	ft_putnbr(long n, int check)
{
	int	a;
	int	len;

	if (n == -2147483648 && check == 0)
		return (ft_putstr("-2147483648"));
	if (check == 1 && n < 0)
		n *= -1;
	len = int_len(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	a = n;
	if (n >= 0 && n <= 9)
	{
		a = a + '0';
		write(1, &a, 1);
	}
	else
	{
		ft_putnbr(n / 10, check);
		ft_putnbr(n % 10, check);
	}
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_puthexa(unsigned long n)
{
	char	*numbers;
	int		len;

	len = 0;
	numbers = "0123456789abcdef";
	if (!n)
		return (ft_putstr("(nil)"));
	if (n >= 16)
		len = ft_puthexa(n / 16);
	if (len == 0)
		len += ft_putstr("0x");
	len++;
	write(1, &numbers[n % 16], 1);
	return (len);
}

int	ft_puthexa_uol(unsigned int n, int uporlow)
{
	char	*numbers;
	int		len;

	len = 0;
	if (uporlow == 0)
		numbers = "0123456789abcdef";
	else
		numbers = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	if (!n)
		return (ft_putstr("(nil)"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 16)
		len = ft_puthexa_uol(n / 16, uporlow);
	len++;
	write(1, &numbers[n % 16], 1);
	return (len);
}
