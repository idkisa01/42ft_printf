/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:29:24 by isabegar          #+#    #+#             */
/*   Updated: 2024/10/28 08:29:24 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2");
		n = 147483648;
		count += 2;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

static	int	replace_char(int c)
{
	if (c == 'x')
		return ('a');
	if (c == 'X')
		return ('A');
	return (c);
}

int	ft_putnbr_hex(unsigned long long n, char c)
{
	int	len;

	len = 0;
	c = replace_char(c);
	if (n >= 16)
	{
		len += ft_putnbr_hex((n / 16), c);
		len += ft_putnbr_hex((n % 16), c);
	}
	else
	{
		if (n >= 10)
			len += ft_putchar(n - 10 + c);
		else
			len += ft_putchar(n + '0');
	}
	return (len);
}

int	ft_putptr(void *ptr)
{
	int					count;
	unsigned long long	pnum;

	count = 0;
	pnum = (unsigned long long)ptr;
	if (!pnum)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hex(pnum, 'x');
	}
	return (count);
}
