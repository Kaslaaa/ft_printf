/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbrs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:27:53 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/01 18:27:55 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_unsigned_numlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb == 0)
		len = 1;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
		ft_print_char(n + '0');
}

int	ft_print_unsigned_nbr(unsigned int nb)
{
	int	len;

	len = ft_print_unsigned_numlen(nb);
	ft_putnbr_unsigned(nb);
	return (len);
}
