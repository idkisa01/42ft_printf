/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:29:49 by isabegar          #+#    #+#             */
/*   Updated: 2024/10/28 08:29:49 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list objects, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(objects, int));
	if (format == 's')
		i += ft_putstr(va_arg(objects, char *));
	if (format == 'x')
		i += ft_putnbr_hex(va_arg(objects, unsigned int), 'x');
	if (format == 'X')
		i += ft_putnbr_hex(va_arg(objects, unsigned int), 'X');
	if (format == 'p')
		i += ft_putptr(va_arg(objects, void *));
	if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(objects, int));
	if (format == 'u')
		i += ft_putnbr_unsigned(va_arg(objects, unsigned int));
	if (format == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	objects;

	count = 0;
	va_start(objects, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_format(objects, *format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(objects);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

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
