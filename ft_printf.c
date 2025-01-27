/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:28:11 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/01 18:28:14 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(const char f_i, va_list args)
{
	if (f_i == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (f_i == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (f_i == 'i' || f_i == 'd')
		return (ft_print_signed_nbr(va_arg(args, int)));
	else if (f_i == 'u')
		return (ft_print_unsigned_nbr(va_arg(args, unsigned int)));
	else if (f_i == '%')
		return (ft_print_char('%'));
	else if (f_i == 'x' || f_i == 'X')
		return (ft_print_hexa_nbr(va_arg(args, unsigned int), f_i));
	else if (f_i == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_check_format(format[i + 1], args);
			i++;
		}
		else
		{
			ft_print_char(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
