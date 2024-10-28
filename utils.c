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

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		ft_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

int	ft_putnbr_hex(unsigned int n, char format)
{
	char	hex_result[9];
	int		i;
	int		count;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = 0;
	while (n > 0)
	{
		if (format == 'x')
			hex_result[i] = "0123456789abcdef"[n % 16];
		else if (format == 'X')
			hex_result[i] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
		i++;
	}
	count = i;
	while (i > 0)
	{
		ft_putchar(hex_result[--i]);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int					count;
	uintptr_t	pnum;

	count = 0;
	pnum = (uintptr_t)ptr;
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hex(pnum, 'x');
	}
	return (count);
}

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
