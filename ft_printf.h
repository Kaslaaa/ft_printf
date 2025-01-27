/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:28:24 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/01 18:43:29 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		ft_print_char(char c);
int		ft_print_str(char *str);

int		ft_print_signed_nbr(int nb);
void	ft_putnbr_signed(int n);

int		ft_print_unsigned_nbr(unsigned int nb);
void	ft_putnbr_unsigned(unsigned int n);

int		ft_print_hexa_nbr(unsigned int nb, char case_format);
void	ft_putnbr_hexa(unsigned int nb, char *hex_str);

int		ft_print_ptr(unsigned long long nb);
void	ft_putnbr_ptr(unsigned long long nb, char *hex_str);

#endif
