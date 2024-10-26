/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabegar <isabegar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:55:05 by isabegar          #+#    #+#             */
/*   Updated: 2024/10/22 20:55:05 by isabegar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_format(va_list objects, char format);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_hex(unsigned int n, char format);
void	ft_putptr(void *ptr);
void	ft_putnbr(int n);
void	ft_putnbr_unsigned(unsigned int n);

#endif