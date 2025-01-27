/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed_nbrs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:27:41 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/01 18:27:43 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_signed_numlen(int nb)
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

void	ft_putnbr_signed(int n)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_print_char('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_signed(n / 10);
		ft_putnbr_signed(n % 10);
	}
	else
		ft_print_char(n + '0');
}

int	ft_print_signed_nbr(int nb)
{
	int	len;

	len = ft_print_signed_numlen(nb);
	ft_putnbr_signed(nb);
	return (len);
}
