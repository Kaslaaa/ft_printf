/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_nbrs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:26:59 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/01 18:27:01 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hexa_numlen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_hexa(unsigned int nb, char *hex_str)
{
	char	c;

	if (nb >= 16)
	{
		ft_putnbr_hexa(nb / 16, hex_str);
		ft_putnbr_hexa(nb % 16, hex_str);
	}
	else
	{
		c = hex_str[nb];
		ft_print_char(c);
	}
}

int	ft_print_hexa_nbr(unsigned int nb, char case_format)
{
	int		len;
	char	*hex_str;

	if (nb == 0)
		return (write (1, "0", 1));
	hex_str = "0123456789abcdef";
	if (case_format == 'X')
		hex_str = "0123456789ABCDEF";
	len = ft_print_hexa_numlen(nb);
	ft_putnbr_hexa(nb, hex_str);
	return (len);
}
