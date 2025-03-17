/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:28:26 by samperez          #+#    #+#             */
/*   Updated: 2025/03/17 14:40:23 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define HEXA_LOW "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"
# define DECIMAL "0123456789"

void	ft_pf_putchar(char c, int *result);
void	ft_pf_putnbr_base(long long n, char *base, int *result);
void	ft_pf_pointer(unsigned long long ptr, int *result);
void	ft_pf_putstr(char *s, int *result);
int		ft_printf(char const *str, ...);

#endif