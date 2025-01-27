/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:27:26 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/01 18:27:28 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr_numlen(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_ptr(unsigned long long nb, char *hex_str)
{
	char	c;

	if (nb >= 16)
	{
		ft_putnbr_ptr(nb / 16, hex_str);
		ft_putnbr_ptr(nb % 16, hex_str);
	}
	else
	{
		c = hex_str[nb];
		ft_print_char(c);
	}
}

int	ft_print_ptr(unsigned long long nb)
{
	int		len;
	char	*hex_str;

	len = 0;
	hex_str = "0123456789abcdef";
	len += write(1, "0x", 2);
	if (nb == 0)
		len += write (1, "0", 1);
	else
	{
		len += ft_print_ptr_numlen(nb);
		ft_putnbr_ptr(nb, hex_str);
	}
	return (len);
}
